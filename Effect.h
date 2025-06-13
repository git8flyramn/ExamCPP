#include "GameObject.h"
#include "global.h"
#include  <vector>
class Effect :
    public GameObject
{
public:
    Effect(Point _pos);
    ~Effect();
    void Update() override;
    void Draw() override;
protected:
private:
    Point pos_;
    std::vector<int> hImage_;
    float animtime_;
    int frame_;
    float frametimer_;
};