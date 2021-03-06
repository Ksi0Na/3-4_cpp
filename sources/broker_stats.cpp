// Copyright 2020 Olga Molchun olgamolchun5@gmail.com

#include <broker_stats.hpp>

BrokerStats::BrokerStats(std::size_t total_, const std::string& account_,
        const std::string& lastDate_)
    : lastDate(lastDate_), account(account_), total(total_) {}

bool operator==(const BrokerStats& lhs, const BrokerStats& rhs) {
    return lhs.total == rhs.total
        && lhs.account == rhs.account
        && lhs.lastDate == rhs.lastDate;
}
