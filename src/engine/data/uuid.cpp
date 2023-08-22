#include "engine/data/uuid.h"

namespace Amethyst {

    const std::string UUID::EMPTY = "00000000-00000000-00000000-00000000";

    UUID::UUID() {
        generate();
    }

    void UUID::generate() {
        rnd1 = getRandomInt();
        rnd2 = getRandomInt();
        rnd3 = getRandomInt();
        rnd4 = getRandomInt();
    }

    std::string UUID::toString() const {
        std::stringstream ss;
        ss << std::hex << std::setfill('0')
           << std::setw(8) << rnd1 << "-"
           << std::setw(4) << (rnd2 >> 16) << "-"
           << std::setw(4) << ((rnd2 & 0xFFFF) | 0x4000) << "-"
           << std::setw(4) << ((rnd3 >> 16) | 0x8000) << "-"
           << std::setw(8) << (rnd3 & 0xFFFF) << std::setw(8) << rnd4;
        
        return ss.str();
    }

    uint32_t UUID::getRandomInt() const {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<uint32_t> dis(0, UINT32_MAX);
        return dis(gen);
    }
}