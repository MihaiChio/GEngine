#include "AssetManager.h"
namespace GEngine
{
    std::shared_ptr<Core> AssetManager::getCore()
    {
        return core.lock();
    }
    void AssetManager::setCore(std::shared_ptr<Core> _core)
    {
        core = _core;
    }
    void AssetManager::setSelf(std::weak_ptr<AssetManager> _am)
    {
        self = _am;
    }
};
