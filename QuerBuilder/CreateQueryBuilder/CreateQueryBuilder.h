#ifndef CREATE_QUERY_BUILDER_H
#define CREATE_QUERY_BUILDER_H

#include "ICreateQueryBuilder.h"
#include <string>
#include <algorithm> // dla std::replace

class CreateQueryBuilder : public ICreateQueryBuilder {
private:
    std::string createQuery;

public:
    CreateQueryBuilder() : createQuery("") {}

    ICreateQueryBuilder& BuildCreate(const std::string& tableName) override {
        createQuery += "CREATE TABLE IF NOT EXISTS " + tableName + "(\n";
        return *this;
    }

    ICreateQueryBuilder& BuildAddType(const std::string& columnName, const std::string& type, bool isPrimaryKey, const std::string& maxLength = "256") override {
        std::string finalType = type;
        if (type == "VARCHAR") {
            finalType += "(" + maxLength + ")";
        }
        createQuery += "\t" + columnName + " " + finalType;
        if (isPrimaryKey) {
            createQuery += " PRIMARY KEY,\n";
        } else {
            createQuery += ",\n";
        }
        return *this;
    }

    ICreateQueryBuilder& BuildForeignKey(const std::string& foreignKey, const std::string& referenceTable, const std::string& referenceKey) override {
        createQuery += "FOREIGN KEY (" + foreignKey + ") REFERENCES " + referenceTable + " (" + referenceKey + "),\n";
        return *this;
    }

    ICreateQueryBuilder& BuildFinal() override {
        // Usunięcie ostatniego przecinka przed zamknięciem nawiasu
        if (createQuery.size() > 2 && createQuery.substr(createQuery.size() - 2) == ",\n") {
            createQuery = createQuery.substr(0, createQuery.size() - 2) + "\n";
        }
        createQuery += ");";
        return *this;
    }

    std::string GetQuery() const override {
        return createQuery;
    }
};

#endif // CREATE_QUERY_BUILDER_H
