#pragma once 

#include "engine/core/system.h"

namespace Content {
    class TestSystem : public System {
        public:
            void init() override;
            void update(double deltaT) override;

        protected:
            void dispose() override;
    };
}