// NovelTD.cpp : Defines the entry point for the application.
//

#include "NovelTD.h"

using namespace std;

int main()
{
	std::unique_ptr<NovelRT::Graphics::TextRect> textRect;

	auto runner = NovelRT::NovelRunner(0, "NovelTD");
	auto console = NovelRT::LoggingService(NovelRT::Utilities::Misc::CONSOLE_LOG_APP);

	auto logoTransform = NovelRT::Transform(NovelRT::Maths::GeoVector2<float>(0.0f, 0.0f), 0, NovelRT::Maths::GeoVector2<float>(1.0f, 1.0f));

	//textRect = runner.getRenderer().lock()->createTextRect(rubyGnomerTextTransform, 2, NovelRT::Graphics::RGBAConfig(0, 255, 0, 255), 70, (fontsDirPath / "Gayathri-Regular.ttf").string());
	//textRect->setText("RubyGnomer");

	cout << "Hello CMake." << endl;
	return 0;
}
