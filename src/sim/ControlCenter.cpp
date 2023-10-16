
#define FORWARD_DECL_ONLY
//#define ROCK
#include "ControlCenter.h"

namespace mars
{

  namespace interfaces
  {
      data_broker::DataBrokerInterface *ControlCenter::theDataBroker = NULL;
      std::shared_ptr<envire::core::EnvireGraph> ControlCenter::envireGraph = nullptr;
      std::shared_ptr<envire::core::TreeView> ControlCenter::graphTreeView = nullptr;
      std::shared_ptr<CollisionInterface> ControlCenter::collision = nullptr;
      std::shared_ptr<MotorManagerInterface> ControlCenter::motors = nullptr;
  }

} // end of namespace mars
