
#pragma once

#include <map>
#include <string>
#include <vector>

namespace mars
{
    namespace interfaces
    {

        struct NodeData;
        struct terrainStruct;

        struct indexMaps_t
        {
            std::string s_Scenename;
            std::map<unsigned long, unsigned long> m_indexMap;
            std::map<unsigned long, unsigned long> m_indexMapJoints;
            std::map<unsigned long, unsigned long> m_indexMapMotors;
            std::map<unsigned long, unsigned long> m_indexMapSensors;
            std::map<unsigned long, unsigned long> m_indexMapControllers;
            std::map<unsigned long, unsigned long> m_indexMapGroupID;
        };

    
        class LoadMeshInterface
        {
        public:
            virtual ~LoadMeshInterface() {}
            virtual void getPhysicsFromMesh(NodeData *node) = 0;
            virtual std::vector<double> getMeshSize(const std::string &filename) = 0;
        };


        class LoadHeightmapInterface
        {
        public:
            virtual ~LoadHeightmapInterface() {}
            virtual void readPixelData(terrainStruct *terrain) = 0;
        };

        class LoadSceneInterface;

        class LoadCenter
        {
        public:
            LoadCenter();
            ~LoadCenter();
      
            unsigned int getMappedSceneByName(const std::string &scenename) const;
            void setMappedSceneName(const std::string &scenename);

            unsigned long getMappedID(unsigned long id,
                                      unsigned int indextype,
                                      unsigned int source) const;

            unsigned int setMappedID(unsigned long id_old,
                                     unsigned long id_new,
                                     unsigned int indextype,
                                     unsigned int source);

            LoadMeshInterface *loadMesh;
            LoadHeightmapInterface *loadHeightmap;
            std::map<std::string, LoadSceneInterface*> loadScene;

        private:
            std::vector<indexMaps_t> maps;
        };

    } // end of namespace interfaces
} // end of namespace mars
