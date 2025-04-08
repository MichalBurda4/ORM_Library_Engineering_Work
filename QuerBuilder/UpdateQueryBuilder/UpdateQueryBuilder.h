#ifndef UPDATE_QUERY_BUILDER_H
#define UPDATE_QUERY_BUILDER_H

#include "IUpdateQueryBuilder.h"
#include <string>

class UpdateQueryBuilder : public IUpdateQueryBuilder {
private:
    std::string updateQuery;

public:
    UpdateQueryBuilder() : updateQuery("") {}

    IUpdateQueryBuilder& BuildUpdate(const std::string& tables) override {
        updateQuery += "UPDATE " + tables + "\n";
        return *this;
    }

    IUpdateQueryBuilder& BuildJoin(const std::string& tables) override {
        updateQuery += "JOIN " + tables + "\n";
        return *this;
    }

    IUpdateQueryBuilder& BuildSet(const std::string& setClause) override {
        updateQuery += "SET " + setClause + " ";
        return *this;
    }

    IUpdateQueryBuilder& BuildWhere(const std::string& condition) override {
        updateQuery += "WHERE " + condition + "\n";
        return *this;
    }

    IUpdateQueryBuilder& BuildOrderByASC(const std::string& columns) override {
        updateQuery += "ORDER BY " + columns + " ASC\n";
        return *this;
    }

    IUpdateQueryBuilder& BuildOrderByDESC(const std::string& columns) override {
        updateQuery += "ORDER BY " + columns + " DESC\n";
        return *this;
    }

    IUpdateQueryBuilder& BuildLimit(int limit) override {
        updateQuery += "LIMIT " + std::to_string(limit) + "\n";
        return *this;
    }

    IUpdateQueryBuilder& BuildOffset(int offset) override {
        updateQuery += "OFFSET " + std::to_string(offset) + "\n";
        return *this;
    }

    std::string GetQuery() const override {
        return updateQuery + ";";
    }
};

#endif // UPDATE_QUERY_BUILDER_H
