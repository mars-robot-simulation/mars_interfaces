
#include "LoadCenter.h"
#include "MARSDefs.h"

namespace mars
{
    namespace interfaces
    {

        using namespace std;

        LoadCenter::LoadCenter() : loadMesh(NULL), loadHeightmap(NULL)
        {
        }

        LoadCenter::~LoadCenter()
        {

        }

        unsigned int LoadCenter::getMappedSceneByName(const std::string &scenename) const
        {
            for (unsigned int i=0; i<maps.size(); i++)
            {
                if (maps[i].s_Scenename==scenename)
                {
                    return i+1;
                }
            }
            return 0;
        }
    
        void LoadCenter::setMappedSceneName(const std::string &scenename)
        {
            indexMaps_t tmp;
            tmp.s_Scenename=scenename;
            maps.push_back(tmp);
        }

        unsigned long LoadCenter::getMappedID(unsigned long id,
                                              unsigned int indextype,
                                              unsigned int source) const
        {
            map<unsigned long, unsigned long>::const_iterator it;

            if(id==0) return 0;
            if(maps.size() < source) return 0;
            switch (indextype)
            {
            case interfaces::MAP_TYPE_NODE:
                it = maps[source-1].m_indexMap.find(id);
                break;
            case interfaces::MAP_TYPE_JOINT:
                it = maps[source-1].m_indexMapJoints.find(id);
                break;
            case interfaces::MAP_TYPE_MOTOR:
                it = maps[source-1].m_indexMapMotors.find(id);
                break;
            case interfaces::MAP_TYPE_SENSOR:
                it = maps[source-1].m_indexMapSensors.find(id);
                break;
            case interfaces::MAP_TYPE_CONTROLLER:
                it = maps[source-1].m_indexMapControllers.find(id);
                break;
            default:
                return 0;
                break;
            }
            if(it->first == id)
            {
                return it->second;
            }
            return 0;
        }

        unsigned int LoadCenter::setMappedID(unsigned long id_old,
                                             unsigned long id_new,
                                             unsigned int indextype,
                                             unsigned int source)
        {
            switch (indextype)
            {
            case interfaces::MAP_TYPE_NODE:
                maps[source-1].m_indexMap[id_old]=id_new;
                return 1;
                break;
            case interfaces::MAP_TYPE_JOINT:
                maps[source-1].m_indexMapJoints[id_old]=id_new;
                return 1;
                break;
            case interfaces::MAP_TYPE_MOTOR:
                maps[source-1].m_indexMapMotors[id_old]=id_new;
                return 1;
                break;
            case interfaces::MAP_TYPE_SENSOR:
                maps[source-1].m_indexMapSensors[id_old]=id_new;
                return 1;
                break;
            case interfaces::MAP_TYPE_CONTROLLER:
                maps[source-1].m_indexMapControllers[id_old]=id_new;
                return 1;
                break;
            default:
                break;
            }
            return 0;
        }

    } // end of namespace interfaces
} // end of namespace mars
