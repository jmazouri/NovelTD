#ifndef NOVELTD_TRANSFORMORIGIN
#define NOVELTD_TRANSFORMORIGIN

namespace NovelTD::Util {
	class TransformOrigin {

	public:
		static const NovelRT::Maths::GeoVector2<float> TopLeft;
		static const NovelRT::Maths::GeoVector2<float> CenterLeft;
		static const NovelRT::Maths::GeoVector2<float> BottomLeft;

		static const NovelRT::Maths::GeoVector2<float> TopCenter;
		static const NovelRT::Maths::GeoVector2<float> Center;
		static const NovelRT::Maths::GeoVector2<float> BottomCenter;

		static const NovelRT::Maths::GeoVector2<float> TopRight;
		static const NovelRT::Maths::GeoVector2<float> CenterRight;
		static const NovelRT::Maths::GeoVector2<float> BottomRight;
	};
}
#endif