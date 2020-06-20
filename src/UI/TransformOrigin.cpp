#include "../../include/NovelTD.h"

namespace NovelTD::Util {
	const NovelRT::Maths::GeoVector2<float> TransformOrigin::TopLeft = NovelRT::Maths::GeoVector2<float>(0.0f, 0.0f);
	const NovelRT::Maths::GeoVector2<float> TransformOrigin::TopCenter = NovelRT::Maths::GeoVector2<float>(0.5f, 0.0f);
	const NovelRT::Maths::GeoVector2<float> TransformOrigin::TopRight = NovelRT::Maths::GeoVector2<float>(1.0f, 0.0f);

	const NovelRT::Maths::GeoVector2<float> TransformOrigin::CenterLeft = NovelRT::Maths::GeoVector2<float>(0.0f, 0.5f);
	const NovelRT::Maths::GeoVector2<float> TransformOrigin::BottomLeft = NovelRT::Maths::GeoVector2<float>(0.0f, 1.0f);

	
	const NovelRT::Maths::GeoVector2<float> TransformOrigin::Center = NovelRT::Maths::GeoVector2<float>(0.5f, 0.5f);
	const NovelRT::Maths::GeoVector2<float> TransformOrigin::BottomCenter = NovelRT::Maths::GeoVector2<float>(0.5f, 1.0f);

	
	const NovelRT::Maths::GeoVector2<float> TransformOrigin::CenterRight = NovelRT::Maths::GeoVector2<float>(0.5f, 1.0f);
	const NovelRT::Maths::GeoVector2<float> TransformOrigin::BottomRight = NovelRT::Maths::GeoVector2<float>(1.0f, 1.0f);
}