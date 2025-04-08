#ifndef IALTER_QUERY_BUILDER_H
#define IALTER_QUERY_BUILDER_H

#include <string>

class IAlterQueryBuilder {
public:
    virtual ~IAlterQueryBuilder() = default;

    virtual IAlterQueryBuilder& BuildAlterTable(const std::string& table) = 0;
    virtual IAlterQueryBuilder& BuildAddColumn(const std::string& column, const std::string& type, const std::string& maxLength = "256") = 0;
    virtual IAlterQueryBuilder& BuildDropColumn(const std::string& column) = 0;
    virtual IAlterQueryBuilder& BuildAlterColumn(const std::string& column, const std::string& type, const std::string& dbType, const std::string& maxLength = "256") = 0;
    virtual IAlterQueryBuilder& BuildChangeColumn(const std::string& column, const std::string& newColumn, const std::string& type) = 0;
    virtual IAlterQueryBuilder& BuildRenameTable(const std::string& table) = 0;
    virtual IAlterQueryBuilder& BuildRenameColumn(const std::string& column, const std::string& newColumn) = 0;
    virtual IAlterQueryBuilder& BuildAddPrimaryKey(const std::string& column) = 0;
    virtual IAlterQueryBuilder& BuildAddConstraint(const std::string& key) = 0;
    virtual IAlterQueryBuilder& BuildForeignKey(const std::string& key) = 0;
    virtual IAlterQueryBuilder& BuildReferences(const std::string& targetTable, const std::string& targetColumn) = 0;
    virtual IAlterQueryBuilder& BuildDropConstraint(const std::string& key) = 0;
    virtual IAlterQueryBuilder& BuildDropForeignKey(const std::string& keyName) = 0;
    virtual IAlterQueryBuilder& BuildFinal() = 0;
    virtual std::string GetQuery() const = 0;
};

#endif // IALTER_QUERY_BUILDER_H
