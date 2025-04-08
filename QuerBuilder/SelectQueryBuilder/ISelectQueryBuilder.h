#ifndef ISELECT_QUERY_BUILDER_H
#define ISELECT_QUERY_BUILDER_H

#include <string>

class ISelectQueryBuilder {
public:
    virtual ~ISelectQueryBuilder() = default;

    virtual ISelectQueryBuilder& BuildSelect(const std::string& columns) = 0;
    virtual ISelectQueryBuilder& BuildFrom(const std::string& tables) = 0;
    virtual ISelectQueryBuilder& BuildJoin(const std::string& tables) = 0;
    virtual ISelectQueryBuilder& BuildWhere(const std::string& condition) = 0;
    virtual ISelectQueryBuilder& GroupBy(const std::string& columns) = 0;
    virtual ISelectQueryBuilder& Having(const std::string& condition) = 0;
    virtual ISelectQueryBuilder& BuildOrderByASC(const std::string& columns) = 0;
    virtual ISelectQueryBuilder& BuildOrderByDESC(const std::string& columns) = 0;
    virtual ISelectQueryBuilder& BuildLimit(int limit) = 0;
    virtual ISelectQueryBuilder& BuildOffset(int offset) = 0;
    virtual std::string GetQuery() const = 0;
};

#endif // ISELECT_QUERY_BUILDER_H
