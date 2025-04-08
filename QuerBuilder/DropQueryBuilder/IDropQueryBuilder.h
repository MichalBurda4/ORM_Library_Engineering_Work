#ifndef IDROP_QUERY_BUILDER_H
#define IDROP_QUERY_BUILDER_H

#include <string>

class IDropQueryBuilder {
public:
    virtual ~IDropQueryBuilder() = default;

    virtual IDropQueryBuilder& BuildDropTable(const std::string& tableName) = 0;
    virtual IDropQueryBuilder& BuildDropDatabase(const std::string& databaseName) = 0;
    virtual std::string GetQuery() const = 0;
};

#endif // IDROP_QUERY_BUILDER_H
