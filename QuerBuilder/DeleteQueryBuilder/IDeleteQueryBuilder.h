#ifndef IDELETE_QUERY_BUILDER_H
#define IDELETE_QUERY_BUILDER_H

#include <string>

class IDeleteQueryBuilder {
public:
    virtual ~IDeleteQueryBuilder() = default;

    virtual IDeleteQueryBuilder& BuildDeleteFrom(const std::string& table) = 0;
    virtual IDeleteQueryBuilder& BuildWhere(const std::string& condition) = 0;
    virtual IDeleteQueryBuilder& BuildOrderByASC(const std::string& columns) = 0;
    virtual IDeleteQueryBuilder& BuildOrderByDESC(const std::string& columns) = 0;
    virtual IDeleteQueryBuilder& BuildLimit(int limit) = 0;
    virtual std::string GetQuery() const = 0;
};

#endif // IDELETE_QUERY_BUILDER_H
