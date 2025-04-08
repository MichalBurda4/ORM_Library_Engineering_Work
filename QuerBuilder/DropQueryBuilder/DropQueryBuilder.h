#ifndef DROP_QUERY_BUILDER_H
#define DROP_QUERY_BUILDER_H

#include "IDropQueryBuilder.h"
#include <string>

class DropQueryBuilder : public IDropQueryBuilder {
private:
    std::string dropQuery;

public:
    DropQueryBuilder() : dropQuery("") {}

    IDropQueryBuilder& BuildDropTable(const std::string& tableName) override {
        dropQuery += "DROP TABLE " + tableName + "\n";
        return *this;
    }

    IDropQueryBuilder& BuildDropDatabase(const std::string& databaseName) override {
        dropQuery += "DROP DATABASE " + databaseName + "\n";
        return *this;
    }

    std::string GetQuery() const override {
        return dropQuery + ";";
    }
};

#endif // DROP_QUERY_BUILDER_H
