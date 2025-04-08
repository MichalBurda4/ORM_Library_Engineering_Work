#ifndef IINSERT_QUERY_BUILDER_H
#define IINSERT_QUERY_BUILDER_H

#include <string>

class IInsertQueryBuilder {
public:
    virtual ~IInsertQueryBuilder() = default;

    virtual IInsertQueryBuilder& BuildInsertInto(const std::string& table, const std::string& columns = "") = 0;
    virtual IInsertQueryBuilder& BuildValues(const std::string& values) = 0;
    virtual std::string GetQuery() const = 0;
};

#endif // IINSERT_QUERY_BUILDER_H
