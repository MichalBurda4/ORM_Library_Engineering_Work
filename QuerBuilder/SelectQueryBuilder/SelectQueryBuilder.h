#ifndef SELECT_QUERY_BUILDER_H
#define SELECT_QUERY_BUILDER_H

#include "ISelectQueryBuilder.h"
#include <string>

class SelectQueryBuilder : public ISelectQueryBuilder {
private:
    std::string selectQuery;

public:
    SelectQueryBuilder() : selectQuery("") {}

    ISelectQueryBuilder& BuildSelect(const std::string& columns) override {
        selectQuery += "SELECT " + columns + "\n";
        return *this;
    }

    ISelectQueryBuilder& BuildFrom(const std::string& tables) override {
        selectQuery += "FROM " + tables + "\n";
        return *this;
    }

    ISelectQueryBuilder& BuildJoin(const std::string& tables) override {
        selectQuery += "JOIN " + tables + "\n";
        return *this;
    }

    ISelectQueryBuilder& BuildWhere(const std::string& condition) override {
        selectQuery += "WHERE " + condition + "\n";
        return *this;
    }

    ISelectQueryBuilder& GroupBy(const std::string& columns) override {
        selectQuery += "GROUP BY " + columns + "\n";
        return *this;
    }

    ISelectQueryBuilder& Having(const std::string& condition) override {
        selectQuery += "HAVING " + condition;
        return *this;
    }

    ISelectQueryBuilder& BuildOrderByASC(const std::string& columns) override {
        selectQuery += "ORDER BY " + columns + " ASC\n";
        return *this;
    }

    ISelectQueryBuilder& BuildOrderByDESC(const std::string& columns) override {
        selectQuery += "ORDER BY " + columns + " DESC\n";
        return *this;
    }

    ISelectQueryBuilder& BuildLimit(int limit) override {
        selectQuery += "LIMIT " + std::to_string(limit) + "\n";
        return *this;
    }

    ISelectQueryBuilder& BuildOffset(int offset) override {
        selectQuery += "OFFSET " + std::to_string(offset) + "\n";
        return *this;
    }

    std::string GetQuery() const override {
        return selectQuery + ";";
    }
};

#endif // SELECT_QUERY_BUILDER_H
