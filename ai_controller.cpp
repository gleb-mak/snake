#include "ai_controller.h"

AiController::AiController(View* v_, Snake* s_, Model* m_):
	v(v_), s(s_), m(m_)
{
	m->onmove(bind(&AiController::update_direct, this));
}

void AiController::update_direct()
{
	Rabbit& nearest_r = m->nearest_rabbit(*s);
	s->set_direct(m->get_direct_to_rabbit(nearest_r, *s));
}
