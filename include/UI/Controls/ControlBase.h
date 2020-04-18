#ifndef NOVELTD_CONTROLBASE
#define NOVELTD_CONTROLBASE

namespace NovelTD::UI {
	class ControlBase {
		friend class CanvasContext;

	protected:
		int layer;
		unsigned long id;
		NovelRT::Transform localTransform = NovelRT::Transform(NovelRT::Maths::GeoVector2<float>(), 0, NovelRT::Maths::GeoVector2<float>(1.0f, 1.0f));
		NovelRT::Transform transform = NovelRT::Transform(NovelRT::Maths::GeoVector2<float>(), 0, NovelRT::Maths::GeoVector2<float>(1.0f, 1.0f));
	public:
		ControlBase(int layer) {
			this->layer = layer;
		};

		virtual void update() = 0;
		virtual unsigned long getId() { return id; }

		virtual void setPosition(const NovelRT::Maths::GeoVector2<float> position) {
			this->localTransform.position() = position;
		}

		virtual const NovelRT::Maths::GeoVector2<float> getPosition() {
			return this->localTransform.position();
		}
	};
}

#endif