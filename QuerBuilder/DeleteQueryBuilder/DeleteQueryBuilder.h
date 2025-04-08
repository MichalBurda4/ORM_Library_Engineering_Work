#ifndef DELETE_QUERY_BUILDER_H
#define DELETE_QUERY_BUILDER_H

#include "IDeleteQueryBuilder.h"
#include <string>

class DeleteQueryBuilder : public IDeleteQueryBuilder {
private:
    std::string deleteQuery;

public:
    DeleteQueryBuilder() : deleteQuery("") {}

    IDeleteQueryBuilder& BuildDeleteFrom(const std::string& table) override {
        deleteQuery += "DELETE FROM " + table + "\n";
        return *this;
    }

    IDeleteQueryBuilder& BuildWhere(const std::string& condition) override {
        deleteQuery += "WHERE " + condition + "\n";
        return *this;
    }

    IDeleteQueryBuilder& BuildOrderByASC(const std::string& columns) override {
        deleteQuery += "ORDER BY " + columns + " ASC\n";
        return *this;
    }

    IDeleteQueryBuilder& BuildOrderByDESC(const std::string& columns) override {
        deleteQuery += "ORDER BY " + columns + " DESC\n";
        return *this;
    }

    IDeleteQueryBuilder& BuildLimit(int limit) override {
        deleteQuery += "LIMIT " + std::to_string(limit) + "\n";
        return *this;
    }

    std::string GetQuery() const override {
        return deleteQuery + ";";
    }
};

#endif // DELETE_QUERY_BUILDER_H
