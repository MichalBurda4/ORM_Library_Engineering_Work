#ifndef ICREATE_QUERY_BUILDER_H
#define ICREATE_QUERY_BUILDER_H

#include <string>

class ICreateQueryBuilder {
public:
    virtual ~ICreateQueryBuilder() = default;

    virtual ICreateQueryBuilder& BuildCreate(const std::string& tableName) = 0;
    virtual ICreateQueryBuilder& BuildAddType(const std::string& columnName, const std::string& type, bool isPrimaryKey, const std::string& maxLength = "256") = 0;
    virtual ICreateQueryBuilder& BuildForeignKey(const std::string& foreignKey, const std::string& referenceTable, const std::string& referenceKey) = 0;
    virtual ICreateQueryBuilder& BuildFinal() = 0;
    virtual std::string GetQuery() const = 0;
};

#endif // ICREATE_QUERY_BUILDER_H
