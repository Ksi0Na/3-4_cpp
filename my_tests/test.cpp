// Copyright 2020 Olga Molchun olgamolchun5@gmail.com

#include <gtest/gtest.h>
// ftp analyzer
#include <ftp_analyzer.hpp>
// STL headers
#include <iostream>
#include <set>
#include <sstream>

TEST(FtpAnalyzer, Stats) {
    FtpAnalyzer analyzer(TEST_FTP_PATH);
    auto stats = analyzer.analyze(std::cout);
    std::multimap<std::string, BrokerStats> expected = {
        {"bcs", BrokerStats{44, "00123456", "20181014"}},
        {"bcs", BrokerStats{46, "00122223", "20181016"}},
        {"bcs", BrokerStats{48, "00123458", "20181018"}},
        {"bcs", BrokerStats{46, "00143456", "20181016"}},
        {"ib", BrokerStats{47, "00100003", "20181017"}},
        {"ib", BrokerStats{48, "00100001", "20181018"}},
        {"ib", BrokerStats{48, "00100002", "20181018"}},
        {"otkritie", BrokerStats{47, "03934523", "20181017"}},
        {"otkritie", BrokerStats{48, "03934520", "20181018"}},
    };
    std::stringstream ss1, ss2;
    for (const auto& record : stats) {
        ss1 << "broker: " << record.first
            << " account: " << record.second.account
            << " files: " << record.second.total
            << " lastdate: " << record.second.lastDate
            << std::endl;
    }
    for (const auto& record : expected) {
        ss2 << "broker: " << record.first
            << " account: " << record.second.account
            << " files: " << record.second.total
            << " lastdate: " << record.second.lastDate
            << std::endl;
    }
    std::set<std::string> s1, s2;
    std::string tmp;
    while (std::getline(ss1, tmp)) {
        s1.insert(tmp);
    }
    while (std::getline(ss2, tmp)) {
        s2.insert(tmp);
    }
    EXPECT_EQ(s1, s2);
}

TEST(FtpAnalyzer, AnalyzerOutput) {
    std::stringstream ss1;
    FtpAnalyzer analyzer(TEST_FTP_PATH);
    analyzer.analyze(ss1);
    std::stringstream ss2(
           R"(ib balance_00100003_20180922.txt
ib balance_00100003_20180929.txt
ib balance_00100003_20181010.txt
ib balance_00100001_20181011.txt
ib balance_00100003_20180927.txt
ib balance_00100002_20181005.txt
ib balance_00100002_20180921.txt
ib balance_00100003_20180918.txt
ib balance_00100002_20180924.txt
ib balance_00100001_20180915.txt
ib balance_00100002_20180913.txt
ib balance_00100003_20181011.txt
ib balance_00100001_20180910.txt
ib balance_00100001_20180923.txt
ib balance_00100002_20180917.txt
ib balance_00100002_20180902.txt
ib balance_00100003_20180924.txt
ib balance_00100002_20180906.txt
ib balance_00100001_20181001.txt
ib balance_00100001_20181009.txt
ib balance_00100002_20181011.txt
ib balance_00100003_20180923.txt
ib balance_00100002_20180915.txt
ib balance_00100002_20181002.txt
ib balance_00100002_20181003.txt
ib balance_00100002_20181014.txt
ib balance_00100003_20181001.txt
ib balance_00100001_20181004.txt
ib balance_00100002_20181009.txt
ib balance_00100003_20180914.txt
ib balance_00100002_20181010.txt
ib balance_00100003_20180912.txt
ib balance_00100001_20180908.txt
ib balance_00100001_20180905.txt
ib balance_00100001_20181017.txt
ib balance_00100002_20180926.txt
ib balance_00100001_20180903.txt
ib balance_00100002_20180920.txt
ib balance_00100001_20180911.txt
ib balance_00100002_20181018.txt
ib balance_00100002_20181007.txt
ib balance_00100003_20180919.txt
ib balance_00100003_20181009.txt
ib balance_00100002_20180919.txt
ib balance_00100003_20180906.txt
ib balance_00100001_20180920.txt
ib balance_00100002_20180929.txt
ib balance_00100001_20181007.txt
ib balance_00100002_20180905.txt
ib balance_00100003_20180928.txt
ib balance_00100002_20181001.txt
ib balance_00100003_20181003.txt
ib balance_00100003_20180925.txt
ib balance_00100002_20181012.txt
ib balance_00100001_20180914.txt
ib balance_00100001_20181012.txt
ib balance_00100001_20180926.txt
ib balance_00100002_20181015.txt
ib balance_00100001_20180922.txt
ib balance_00100002_20181013.txt
ib balance_00100001_20181016.txt
ib balance_00100003_20181006.txt
ib balance_00100002_20181006.txt
ib balance_00100002_20181008.txt
ib balance_00100001_20180917.txt
ib balance_00100001_20180930.txt
ib balance_00100003_20180921.txt
ib balance_00100001_20181006.txt
ib balance_00100002_20180910.txt
ib balance_00100001_20180928.txt
ib balance_00100001_20180912.txt
ib balance_00100003_20181005.txt
ib balance_00100003_20180926.txt
ib balance_00100001_20181002.txt
ib balance_00100001_20181005.txt
ib balance_00100001_20180921.txt
ib balance_00100003_20181008.txt
ib balance_00100003_20180902.txt
ib balance_00100003_20181007.txt
ib balance_00100003_20180901.txt
ib balance_00100001_20180916.txt
ib balance_00100003_20180920.txt
ib balance_00100002_20180923.txt
ib balance_00100002_20180903.txt
ib balance_00100001_20180907.txt
ib balance_00100002_20180927.txt
ib balance_00100001_20180913.txt
ib balance_00100001_20180924.txt
ib balance_00100003_20181017.txt
ib balance_00100002_20180918.txt
ib balance_00100002_20181016.txt
ib balance_00100002_20180925.txt
ib balance_00100001_20180902.txt
ib balance_00100002_20180907.txt
ib balance_00100002_20180911.txt
ib balance_00100001_20180904.txt
ib balance_00100001_20181015.txt
ib balance_00100003_20180916.txt
ib balance_00100003_20180908.txt
ib balance_00100001_20180918.txt
ib balance_00100002_20180901.txt
ib balance_00100002_20180916.txt
ib balance_00100003_20180910.txt
ib balance_00100002_20180922.txt
ib balance_00100001_20181018.txt
ib balance_00100001_20181010.txt
ib balance_00100002_20180914.txt
ib balance_00100002_20181004.txt
ib balance_00100001_20181003.txt
ib balance_00100001_20181014.txt
ib balance_00100003_20180915.txt
ib balance_00100003_20181016.txt
ib balance_00100001_20180909.txt
ib balance_00100002_20180908.txt
ib balance_00100003_20180917.txt
ib balance_00100001_20180929.txt
ib balance_00100003_20181002.txt
ib balance_00100002_20181017.txt
ib balance_00100001_20180919.txt
ib balance_00100003_20180905.txt
ib balance_00100003_20180930.txt
ib balance_00100003_20180913.txt
ib balance_00100002_20180912.txt
ib balance_00100003_20180911.txt
ib balance_00100001_20180906.txt
ib balance_00100003_20181012.txt
ib balance_00100003_20181004.txt
ib balance_00100002_20180909.txt
ib balance_00100003_20180904.txt
ib balance_00100002_20180928.txt
ib balance_00100002_20180930.txt
ib balance_00100003_20180909.txt
ib balance_00100001_20180927.txt
ib balance_00100001_20181008.txt
ib balance_00100003_20181015.txt
ib balance_00100001_20180901.txt
ib balance_00100003_20181013.txt
ib balance_00100001_20181013.txt
ib balance_00100001_20180925.txt
ib balance_00100003_20181014.txt
ib balance_00100002_20180904.txt
ib balance_00100003_20180907.txt
ib balance_00100003_20180903.txt
bcs balance_00123456_20181001.txt
bcs balance_00122223_20181002.txt
bcs balance_00123458_20181012.txt
bcs balance_00123458_20180926.txt
bcs balance_00123456_20181007.txt
bcs balance_00143456_20180918.txt
bcs balance_00143456_20180922.txt
bcs balance_00143456_20180916.txt
bcs balance_00122223_20181011.txt
bcs balance_00123458_20180911.txt
bcs balance_00143456_20180907.txt
bcs balance_00123456_20180904.txt
bcs balance_00143456_20181016.txt
bcs balance_00123456_20181002.txt
bcs balance_00123458_20180909.txt
bcs balance_00123458_20180908.txt
bcs balance_00122223_20180907.txt
bcs balance_00122223_20181013.txt
bcs balance_00123456_20180909.txt
bcs balance_00123456_20180923.txt
bcs balance_00143456_20180920.txt
bcs balance_00122223_20181016.txt
bcs balance_00122223_20180910.txt
bcs balance_00123458_20181011.txt
bcs balance_00143456_20181007.txt
bcs balance_00143456_20181010.txt
bcs balance_00123456_20180905.txt
bcs balance_00143456_20180914.txt
bcs balance_00123456_20180906.txt
bcs balance_00122223_20181014.txt
bcs balance_00123456_20180910.txt
bcs balance_00123458_20180920.txt
bcs balance_00122223_20180912.txt
bcs balance_00123456_20180915.txt
bcs balance_00123458_20181001.txt
bcs balance_00123458_20180921.txt
bcs balance_00122223_20181001.txt
bcs balance_00123458_20181002.txt
bcs balance_00122223_20181015.txt
bcs balance_00143456_20181003.txt
bcs balance_00143456_20180905.txt
bcs balance_00143456_20180923.txt
bcs balance_00123458_20180918.txt
bcs balance_00122223_20181010.txt
bcs balance_00123456_20180918.txt
bcs balance_00122223_20180901.txt
bcs balance_00123458_20181015.txt
bcs balance_00123456_20180919.txt
bcs balance_00123458_20181014.txt
bcs balance_00123456_20181014.txt
bcs balance_00143456_20180904.txt
bcs balance_00122223_20180925.txt
bcs balance_00122223_20180903.txt
bcs balance_00143456_20180908.txt
bcs balance_00123458_20181017.txt
bcs balance_00143456_20180921.txt
bcs balance_00143456_20180901.txt
bcs balance_00143456_20180903.txt
bcs balance_00122223_20180911.txt
bcs balance_00123458_20180922.txt
bcs balance_00122223_20180914.txt
bcs balance_00143456_20181009.txt
bcs balance_00123456_20181003.txt
bcs balance_00143456_20180928.txt
bcs balance_00123458_20180924.txt
bcs balance_00143456_20181005.txt
bcs balance_00122223_20180929.txt
bcs balance_00143456_20180917.txt
bcs balance_00123456_20180902.txt
bcs balance_00123458_20181013.txt
bcs balance_00123458_20180906.txt
bcs balance_00123456_20180929.txt
bcs balance_00123456_20180912.txt
bcs balance_00143456_20180927.txt
bcs balance_00123456_20180927.txt
bcs balance_00123458_20180910.txt
bcs balance_00122223_20180915.txt
bcs balance_00123458_20180913.txt
bcs balance_00123458_20180901.txt
bcs balance_00122223_20181012.txt
bcs balance_00143456_20180930.txt
bcs balance_00123456_20181013.txt
bcs balance_00122223_20180928.txt
bcs balance_00123458_20180903.txt
bcs balance_00123456_20181011.txt
bcs balance_00123458_20181016.txt
bcs balance_00122223_20180913.txt
bcs balance_00123458_20181004.txt
bcs balance_00122223_20180927.txt
bcs balance_00143456_20181015.txt
bcs balance_00123458_20181008.txt
bcs balance_00122223_20180930.txt
bcs balance_00123456_20180924.txt
bcs balance_00143456_20181012.txt
bcs balance_00123458_20180905.txt
bcs balance_00123458_20180917.txt
bcs balance_00143456_20181014.txt
bcs balance_00122223_20180923.txt
bcs balance_00123458_20181007.txt
bcs balance_00143456_20180912.txt
bcs balance_00122223_20180916.txt
bcs balance_00143456_20180924.txt
bcs balance_00123458_20181010.txt
bcs balance_00143456_20181006.txt
bcs balance_00122223_20181008.txt
bcs balance_00143456_20181013.txt
bcs balance_00122223_20180906.txt
bcs balance_00123456_20180907.txt
bcs balance_00123456_20181006.txt
bcs balance_00123456_20180916.txt
bcs balance_00123456_20180914.txt
bcs balance_00122223_20181005.txt
bcs balance_00143456_20180925.txt
bcs balance_00123456_20180925.txt
bcs balance_00123458_20180925.txt
bcs balance_00123458_20181005.txt
bcs balance_00143456_20180915.txt
bcs balance_00122223_20180905.txt
bcs balance_00122223_20180926.txt
bcs balance_00123456_20180913.txt
bcs balance_00122223_20181004.txt
bcs balance_00143456_20181008.txt
bcs balance_00123456_20180921.txt
bcs balance_00122223_20181009.txt
bcs balance_00122223_20180908.txt
bcs balance_00122223_20180919.txt
bcs balance_00123458_20181018.txt
bcs balance_00123456_20180928.txt
bcs balance_00122223_20181007.txt
bcs balance_00122223_20180904.txt
bcs balance_00123458_20180923.txt
bcs balance_00143456_20180906.txt
bcs balance_00123458_20180929.txt
bcs balance_00143456_20181002.txt
bcs balance_00122223_20180921.txt
bcs balance_00123458_20180915.txt
bcs balance_00123458_20180930.txt
bcs balance_00123458_20180928.txt
bcs balance_00123458_20180927.txt
bcs balance_00123456_20180920.txt
bcs balance_00143456_20180919.txt
bcs balance_00143456_20180909.txt
bcs balance_00143456_20180913.txt
bcs balance_00123456_20181012.txt
bcs balance_00122223_20181003.txt
bcs balance_00122223_20181006.txt
bcs balance_00123456_20181009.txt
bcs balance_00123456_20181008.txt
bcs balance_00123458_20180912.txt
bcs balance_00122223_20180924.txt
bcs balance_00122223_20180909.txt
bcs balance_00143456_20180929.txt
bcs balance_00123458_20180902.txt
bcs balance_00143456_20181011.txt
bcs balance_00123456_20180922.txt
bcs balance_00123456_20181004.txt
bcs balance_00123456_20181005.txt
bcs balance_00123458_20180907.txt
bcs balance_00123456_20180901.txt
bcs balance_00123456_20180911.txt
bcs balance_00123458_20181003.txt
bcs balance_00123456_20180908.txt
bcs balance_00143456_20180902.txt
bcs balance_00122223_20180902.txt
bcs balance_00123458_20180914.txt
bcs balance_00143456_20180926.txt
bcs balance_00143456_20181004.txt
bcs balance_00143456_20180911.txt
bcs balance_00123456_20180926.txt
bcs balance_00123458_20180904.txt
bcs balance_00123456_20180903.txt
bcs balance_00123458_20181009.txt
bcs balance_00123458_20181006.txt
bcs balance_00122223_20180917.txt
bcs balance_00143456_20181001.txt
bcs balance_00122223_20180918.txt
bcs balance_00123456_20180917.txt
bcs balance_00123456_20181010.txt
bcs balance_00123458_20180919.txt
bcs balance_00123456_20180930.txt
bcs balance_00143456_20180910.txt
bcs balance_00123458_20180916.txt
bcs balance_00122223_20180922.txt
bcs balance_00122223_20180920.txt
otkritie balance_03934523_20180930.txt
otkritie balance_03934523_20180926.txt
otkritie balance_03934523_20180929.txt
otkritie balance_03934523_20181015.txt
otkritie balance_03934523_20180908.txt
otkritie balance_03934523_20181012.txt
otkritie balance_03934520_20181002.txt
otkritie balance_03934523_20180917.txt
otkritie balance_03934523_20180922.txt
otkritie balance_03934520_20181008.txt
otkritie balance_03934523_20181010.txt
otkritie balance_03934520_20180921.txt
otkritie balance_03934520_20180903.txt
otkritie balance_03934523_20180928.txt
otkritie balance_03934523_20180924.txt
otkritie balance_03934520_20180928.txt
otkritie balance_03934520_20180925.txt
otkritie balance_03934520_20180926.txt
otkritie balance_03934520_20180914.txt
otkritie balance_03934523_20181008.txt
otkritie balance_03934520_20180920.txt
otkritie balance_03934523_20180927.txt
otkritie balance_03934520_20181014.txt
otkritie balance_03934520_20180905.txt
otkritie balance_03934520_20181012.txt
otkritie balance_03934523_20181004.txt
otkritie balance_03934520_20180915.txt
otkritie balance_03934520_20180922.txt
otkritie balance_03934520_20180911.txt
otkritie balance_03934520_20180909.txt
otkritie balance_03934523_20180901.txt
otkritie balance_03934523_20180905.txt
otkritie balance_03934523_20180902.txt
otkritie balance_03934523_20181002.txt
otkritie balance_03934523_20180918.txt
otkritie balance_03934523_20180916.txt
otkritie balance_03934520_20181004.txt
otkritie balance_03934523_20181006.txt
otkritie balance_03934520_20180919.txt
otkritie balance_03934520_20181016.txt
otkritie balance_03934520_20180906.txt
otkritie balance_03934523_20180913.txt
otkritie balance_03934523_20181007.txt
otkritie balance_03934520_20181015.txt
otkritie balance_03934523_20180923.txt
otkritie balance_03934520_20180917.txt
otkritie balance_03934520_20180924.txt
otkritie balance_03934520_20180912.txt
otkritie balance_03934523_20181011.txt
otkritie balance_03934520_20181011.txt
otkritie balance_03934520_20181010.txt
otkritie balance_03934520_20181001.txt
otkritie balance_03934523_20181017.txt
otkritie balance_03934523_20181014.txt
otkritie balance_03934523_20180912.txt
otkritie balance_03934520_20180930.txt
otkritie balance_03934520_20181005.txt
otkritie balance_03934523_20180920.txt
otkritie balance_03934523_20181016.txt
otkritie balance_03934523_20180921.txt
otkritie balance_03934520_20180927.txt
otkritie balance_03934523_20180910.txt
otkritie balance_03934520_20181006.txt
otkritie balance_03934520_20181017.txt
otkritie balance_03934523_20181009.txt
otkritie balance_03934523_20181013.txt
otkritie balance_03934523_20180909.txt
otkritie balance_03934523_20180915.txt
otkritie balance_03934520_20181013.txt
otkritie balance_03934520_20181003.txt
otkritie balance_03934523_20180903.txt
otkritie balance_03934520_20180913.txt
otkritie balance_03934523_20180907.txt
otkritie balance_03934520_20180929.txt
otkritie balance_03934523_20181005.txt
otkritie balance_03934523_20180925.txt
otkritie balance_03934523_20180906.txt
otkritie balance_03934520_20180902.txt
otkritie balance_03934520_20180918.txt
otkritie balance_03934520_20180908.txt
otkritie balance_03934523_20180919.txt
otkritie balance_03934520_20181007.txt
otkritie balance_03934520_20180904.txt
otkritie balance_03934520_20180910.txt
otkritie balance_03934520_20181009.txt
otkritie balance_03934523_20181001.txt
otkritie balance_03934523_20180904.txt
otkritie balance_03934520_20180923.txt
otkritie balance_03934520_20180916.txt
otkritie balance_03934523_20180911.txt
otkritie balance_03934523_20180914.txt
otkritie balance_03934520_20180901.txt
otkritie balance_03934520_20180907.txt
otkritie balance_03934520_20181018.txt
otkritie balance_03934523_20181003.txt
)");
    std::set<std::string> s1, s2;
    std::string tmp;
    while (std::getline(ss1, tmp)) {
        s1.insert(tmp);
    }
    while (std::getline(ss2, tmp)) {
        s2.insert(tmp);
    }
    EXPECT_EQ(s1, s2);
}
