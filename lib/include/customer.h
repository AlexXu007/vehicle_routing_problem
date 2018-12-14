#pragma once

#include <cstdint>
#include <utility>
#include <vector>
#include <transportation_quantity.h>

namespace vrp {
/// Customer representation
class Customer {
public:
    int id = 0; ///< customer id. 0 is reserved for depot
    int demand = 0;    ///< customer demand
    TrQuant trquant_c; ///customer demand quantity (of 1 item)
    std::pair<int, int> hard_tw = {};   ///< hard time window
    std::pair<int, int> soft_tw = {};   ///< soft time window
    int service_time = 0;   ///< customer service time
    std::vector<int> suitable_vehicles = {};    ///< vehicles that can serve
                                                /// the customer
};
}  // vrp
