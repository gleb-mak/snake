#include "model.h"
#include "view.h"

using namespace std::placeholders;

class AiController
{
public:
	AiController(View* v_, Snake* s_, Model* m_);
private:
	void update_direct();
    View* v;
    Snake* s;
	Model* m;
};
