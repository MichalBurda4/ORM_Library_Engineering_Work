#ifndef INSERT_QUERY_BUILDER_H
#define INSERT_QUERY_BUILDER_H

#include <string>

class InsertQueryBuilder {
private:
    std::string insertQuery;

public:
    // Konstruktor domyślny
    InsertQueryBuilder() : insertQuery("") {}

    // Metoda do budowania części INSERT INTO
    InsertQueryBuilder& BuildInsertInto(const std::string& table, const std::string& columns = "") {
        insertQuery += "INSERT INTO " + table + " ";
        if (!columns.empty()) {
            insertQuery += "(" + columns + ") \n";
        }
        return *this;
    }

    // Metoda do budowania części VALUES
    InsertQueryBuilder& BuildValues(const std::string& values) {
        insertQuery += "VALUES (" + values + ")";
        return *this;
    }

    // Zwraca finalne zapytanie
    std::string GetQuery() const {
        return insertQuery + ";";
    }
};

#endif // INSERT_QUERY_BUILDER_H
