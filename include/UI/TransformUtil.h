
#ifndef NOVELTD_TRANSFORMUTIL
#define NOVELTD_TRANSFORMUTIL

namespace NovelTD::Util {
	class TransformUtil {

	public:
		static NovelRT::Transform scaleRelative(const NovelRT::Transform& t, const NovelRT::Maths::GeoVector2<float> origin = TransformOrigin::Center) {
			auto ret = NovelRT::Transform(t);
		}
	};
}
#endif