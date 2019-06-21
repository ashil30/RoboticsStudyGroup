#include <ignition/math/Pose3.hh>
#include "gazebo/physics/physics.hh"
#include "gazebo/common/common.hh"
#include "gazebo/gazebo.hh"

namespace gazebo
{
class mazeworld : public WorldPlugin
{
  public: void Load(physics::WorldPtr _parent, sdf::ElementPtr /*_sdf*/)
  {
    //  Insert model from file via function call.
    // The filename must be in the GAZEBO_MODEL_PATH environment variable.
    _parent->InsertModelFile("model://4wheelbot");
    _parent->InsertModelFile("model://maze1");   

    
  }
};

// Register this plugin with the simulator
GZ_REGISTER_WORLD_PLUGIN(mazeworld)
}