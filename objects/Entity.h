class LightEmission;
class Surface;
class Position;
class Orientation;

class Entity {
    public:
        virtual LightEmission * GetLightEmission()=0;
        virtual Body * GetBody()=0;
        virtual Position * GetPosition()=0;
        virtual Orientation * GetOrientation()=0;
        virtual ~Entity();
};