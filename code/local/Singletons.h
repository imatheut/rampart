//This provides an access to a singleton which storage is provided by a gf::SingletonStorage<T>.
#ifndef RAMPART_SINGLETONS_H
#define RAMPART_SINGLETONS_H

#include <gf/Singleton.h>
#include <gf/ResourceManager.h>

namespace rampart {
  // using so any source file that includes this will be able to use "gResourceManager"  
  extern gf::Singleton<gf::ResourceManager> gResourceManager;
}

#endif // RAMPART_SINGLETONS_H
