#include <gazebo/common/common.hh>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
namespace gazebo
{
    class plugin_tutorial : public WorldPlugin
    {
        public: void Load(physics::WorldPtr _parent, sdf::ElementPtr /*_sdf*/)
                {
        //Inserting The Model files now
        _parent->InsertModelFile("model://navigationWorld");
        _parent->InsertModelFile("model://twoWheel");

    }
    };
    GZ_REGISTER_WORLD_PLUGIN(plugin_tutorial)
}
