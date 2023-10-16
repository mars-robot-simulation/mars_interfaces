
#prama once

namespace mars
{

    namespace sim
    {
        class SimEntity;
    }

    namespace interfaces
    {

        /**
         * The interface for notifying components of changes in simulation entities.
         *
         */
        class EntitySubscriberInterface
        {

        public:
            EntitySubscriberInterface(void) {};
            virtual ~EntitySubscriberInterface(void) {};
            virtual void registerEntity(sim::SimEntity *) = 0;

        };

    } // end of namespace interfaces
} // end of namespace mars
