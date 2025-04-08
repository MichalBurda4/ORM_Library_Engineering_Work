#ifndef IUPDATE_QUERY_BUILDER_H
#define IUPDATE_QUERY_BUILDER_H

#include <string>

class IUpdateQueryBuilder {
public:
    virtual ~IUpdateQueryBuilder() = default;

    virtual IUpdateQueryBuilder& BuildUpdate(const std::string& tables) = 0;
    virtual IUpdateQueryBuilder& BuildJoin(const std::string& tables) = 0;
    virtual IUpdateQueryBuilder& BuildSet(const std::string& setClause) = 0;
    virtual IUpdateQueryBuilder& BuildWhere(const std::string& condition) = 0;
    virtual IUpdateQueryBuilder& BuildOrderByASC(const std::string& columns) = 0;
    virtual IUpdateQueryBuilder& BuildOrderByDESC(const std::string& columns) = 0;
    virtual IUpdateQueryBuilder& BuildLimit(int limit) = 0;
    virtual IUpdateQueryBuilder& BuildOffset(int offset) = 0;
    virtual std::string GetQuery() const = 0;
};

#endif // IUPDATE_QUERY_BUILDER_H
