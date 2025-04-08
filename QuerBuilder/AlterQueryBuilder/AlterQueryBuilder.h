#ifndef ALTER_QUERY_BUILDER_H
#define ALTER_QUERY_BUILDER_H

#include "IAlterQueryBuilder.h"
#include <string>

class AlterQueryBuilder : public IAlterQueryBuilder {
private:
    std::string alterQuery;

public:
    AlterQueryBuilder() : alterQuery("") {}

    IAlterQueryBuilder& BuildAlterTable(const std::string& table) override {
        alterQuery += "ALTER TABLE " + table + "\n";
        return *this;
    }

    IAlterQueryBuilder& BuildAddColumn(const std::string& column, const std::string& type, const std::string& maxLength = "256") override {
        std::string finalType = type;
        if (type == "VARCHAR") {
            finalType += "(" + maxLength + ")";
        }
        alterQuery += "ADD COLUMN " + column + " " + finalType + "\n";
        return *this;
    }

    IAlterQueryBuilder& BuildDropColumn(const std::string& column) override {
        alterQuery += "DROP COLUMN " + column + "\n";
        return *this;
    }

    IAlterQueryBuilder& BuildAlterColumn(const std::string& column, const std::string& type, const std::string& dbType, const std::string& maxLength = "256") override {
        std::string finalType = type;
        if (type == "VARCHAR") {
            finalType += "(" + maxLength + ")";
        }

        if (dbType == "postgresql") {
            alterQuery += "ALTER COLUMN " + column + " TYPE " + finalType + " USING " + column + "::" + finalType + "\n";
        } else if (dbType == "mysql") {
            alterQuery += "MODIFY COLUMN " + column + " " + finalType + "\n";
        }
        return *this;
    }

    IAlterQueryBuilder& BuildChangeColumn(const std::string& column, const std::string& newColumn, const std::string& type) override {
        alterQuery += "CHANGE COLUMN " + column + " " + newColumn + " " + type + "\n";
        return *this;
    }

    IAlterQueryBuilder& BuildRenameTable(const std::string& table) override {
        alterQuery += "RENAME TO " + table + "\n";
        return *this;
    }

    IAlterQueryBuilder& BuildRenameColumn(const std::string& column, const std::string& newColumn) override {
        alterQuery += "RENAME COLUMN " + column + " TO " + newColumn + "\n";
        return *this;
    }

    IAlterQueryBuilder& BuildAddPrimaryKey(const std::string& column) override {
        alterQuery += "ADD PRIMARY KEY(" + column + ")\n";
        return *this;
    }

    IAlterQueryBuilder& BuildAddConstraint(const std::string& key) override {
        alterQuery += "ADD CONSTRAINT " + key + "\n";
        return *this;
    }

    IAlterQueryBuilder& BuildForeignKey(const std::string& key) override {
        alterQuery += "FOREIGN KEY (" + key + ")\n";
        return *this;
    }

    IAlterQueryBuilder& BuildReferences(const std::string& targetTable, const std::string& targetColumn) override {
        alterQuery += "REFERENCES " + targetTable + " (" + targetColumn + ")\n";
        return *this;
    }

    IAlterQueryBuilder& BuildDropConstraint(const std::string& key) override {
        alterQuery += "DROP CONSTRAINT " + key + "\n";
        return *this;
    }

    IAlterQueryBuilder& BuildDropForeignKey(const std::string& keyName) override {
        alterQuery += "DROP FOREIGN KEY " + keyName + "\n";
        return *this;
    }

    IAlterQueryBuilder& BuildFinal() override {
        alterQuery += ";";
        return *this;
    }

    std::string GetQuery() const override {
        return alterQuery;
    }
};

#endif // ALTER_QUERY_BUILDER_H
