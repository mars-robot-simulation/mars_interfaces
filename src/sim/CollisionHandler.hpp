#pragma once

#include "../ContactData.hpp"

#include <memory>
#include <vector>

namespace mars
{

    namespace interfaces
    {

        class CollisionInterface;

        class CollisionHandler {

        public:
            virtual ~CollisionHandler() {}
            virtual void getContacts(std::shared_ptr<CollisionInterface> firstSpace,
                                     std::shared_ptr<CollisionInterface> secondSpace,
                                     std::vector<ContactData> &contactVector) = 0;
        };

    } // end of namespace interfaces
} // end of namespace mars
