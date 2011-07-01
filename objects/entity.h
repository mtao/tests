class LightSource;
class Surface;
class Position;
class Orientation;

class Entity {
    public:
        virtual LightSource * GetLightSource()=0;
        virtual Body * GetBody()=0;
        virtual Position * GetPosition()=0;
        virtual ~Entity();
};
