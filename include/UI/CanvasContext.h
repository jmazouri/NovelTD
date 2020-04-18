#include "Controls\ControlBase.h"
#include "Controls\Button.h"

#ifndef NOVELTD_CANVASCONTEXT
#define NOVELTD_CANVASCONTEXT

namespace NovelTD::UI {
	typedef std::vector<std::shared_ptr<ControlBase>> ControlVector;

	class CanvasContext {

		static unsigned long _currentId;

		NovelRT::Maths::GeoVector2<float> position;
		NovelRT::NovelRunner& _runner;
		std::unordered_map<unsigned long, std::shared_ptr<ControlBase>> _controlMap;

	public:
		CanvasContext(NovelRT::NovelRunner& runner, const NovelRT::Transform& transform, int layer);
		void update();

		std::shared_ptr<Button> addButton(const std::string& text);
	};
}
#endif