#include <iostream>
#include <string>
#include <vector>
#include <jdbc/mysql_driver.h>
#include <jdbc/mysql_connection.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/prepared_statement.h>


///helper function, similar to the 'implode' fn in PHP
std::string implode(const std::vector<std::string>& vec, const std::string& separator) {
    std::string result;
    for (size_t i = 0; i < vec.size(); ++i) {
        result += vec[i];
        if (i != vec.size() - 1) {
            result += separator;
        }
    }
    return result;
}


/**
* Custom ORM basically copied my implementation in php to simplify my work
* original impl - https://github.com/munenepeter/dev-chungu/blob/main/Core/Database/QueryBuilder.php
*/

class QueryBuilder {
private:
  sql::Connection* connection;

public:
  QueryBuilder(sql::Connection* connection) {
    this->connection = connection;
  }
//abstraction to run all queries to avoid code duplication
  std::vector<std::vector<std::string>> runQuery(std::string sql) {
    sql::Statement* statement = connection->createStatement();
    sql::ResultSet* resultSet = statement->executeQuery(sql);

    std::vector<std::vector<std::string>> results;
    while (resultSet->next()) {
      std::vector<std::string> row;
      int columnCount = resultSet->getMetaData()->getColumnCount();
      for (int i = 1; i <= columnCount; i++) {
        row.push_back(resultSet->getString(i));
      }
      results.push_back(row);
    }

    delete resultSet;
    delete statement;
    return results;
  }
 //SELECT * FROM {table} ORDER BY `created_at` DESC;
  std::vector<std::vector<std::string>> selectAll(std::string table) {
    std::string sql = "SELECT * FROM " + table + " ORDER BY `created_at` DESC;";
    return runQuery(sql);
  }
//SELECT * FROM {table};
  std::vector<std::vector<std::string>> select(std::string table, std::vector<std::string> values) {
    std::string sql = "SELECT " + implode(values, ",") + " FROM " + table;
    return runQuery(sql);
  }
//SELECT {col1, col2, ...} FROM {table} WHERE {condtion} {value};
  std::vector<std::vector<std::string>> selectWhere(std::string table, std::vector<std::string> values, std::vector<std::string> condition) {
    std::string sql = "SELECT " + implode(values, ",") + " FROM " + table + " WHERE ";
    for (int i = 0; i < condition.size(); i++) {
      if (i == 0) {
        sql += condition[i];
      } else {
        sql += " = \"" + condition[i] + "\"";
      }
    }
    return runQuery(sql);
  }
//UPDATE {table} SET {newvalue} WHERE {oldvalue} = {value}
  bool update(std::string table, std::string dataToUpdate, std::string where, std::string isValue) {
    std::string sql = "UPDATE " + table + " SET " + dataToUpdate + " WHERE `" + where + "` = \"" + isValue + "\"";
    runQuery(sql);  
    return true;
  }
//DELETE FROM {table} WHERE {col} = {value}
  bool deleteRow(std::string table, std::string column, std::string isValue) {
    std::string sql = "DELETE FROM " + table + " WHERE `" + column + "` = \"" + isValue + "\"";
    runQuery(sql);  
    return true;
  }
//INSERT INTO {table} {:col1, :col2, ...} VALUES({val1,val2,...})
  bool insert(std::string table, std::vector<std::string> parameters) {
    std::string placeholders;
    std::string values;
    for (int i = 0; i < parameters.size(); i++) {
      if (i > 0) {
        placeholders += ", ";
        values += ", ";
      }
      placeholders += "?";
      values += "'" + parameters[i] + "'";
    }

    std::string sql = "INSERT INTO " + table + " (" + placeholders + ") VALUES (" + values + ")";
    runQuery(sql);  
    return true;
  }
};


int main() {
    //intiate the driver
  sql::mysql::MySQL_Driver* driver;
  sql::Connection* connection;

  try {
      //set the values of the sql server to read from
    driver = sql::mysql::get_mysql_driver_instance();
    connection = driver->connect("tcp://127.0.0.1:3307", "root", "peter");
    connection->setSchema("studentz");
    //call the querybuildrr
    QueryBuilder queryBuilder(connection);
    std::vector<std::vector<std::string>> results = queryBuilder.selectAll("users");
    for (const auto& row : results) {
      for (const auto& value : row) {
        std::cout << value << " ";
      }
      std::cout << std::endl;
    }
  } catch (sql::SQLException& e) {
    std::cerr << "SQL Exception: " << e.what() << std::endl;
  }
  //close db connection
  delete connection;
  return 0;
}
