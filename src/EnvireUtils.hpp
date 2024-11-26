#pragma once

// namespace envire
// {
//     namespace core
//     {
//         class EnvireGraph;
//         class TreeView;
//     }
// }

namespace mars
{
    namespace interfaces
    {
        // utils functions
        template<typename T>
        envire::core::Item<T>& searchForTopItem(std::shared_ptr<envire::core::EnvireGraph> &envireGraph,
                                                std::shared_ptr<envire::core::TreeView> &graphTreeView,
                                                envire::core::FrameId startNode,
                                                envire::core::FrameId *foundNode=nullptr)
        {
            bool done = false;
            envire::core::FrameId frame = startNode;
            bool found = false;
            envire::core::Item<T> rT;
            while(!done)
            {
                try
                {
                    auto& it = envireGraph->getItem<envire::core::Item<T>>(frame);
                    if(foundNode != nullptr)
                    {
                        *foundNode = frame;
                    }
                    return *it;
                }
                catch (...)
                {
                }
                if(!done)
                {
                    const auto& vertex = envireGraph->vertex(frame);
                    const auto& parentVertex = graphTreeView->tree[vertex].parent;
                    // todo: check if this check is correct
                    if(parentVertex)
                    {
                        frame = envireGraph->getFrameId(parentVertex);
                    }
                    else
                    {
                        done = true;
                    }
                }
            }
            throw envire::core::UnknownFrameException(startNode);
            return rT;
        }

    } // end of namespace interfaces
} // end of namespace mars
