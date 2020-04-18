// NovelTD.cpp : Defines the entry point for the application.
//

#include "../include/NovelTD.h"

using namespace std;

int main()
{
	std::filesystem::path executableDirPath = NovelRT::Utilities::Misc::getExecutableDirPath();
	std::filesystem::path resourcesDirPath = executableDirPath / "res";
	std::filesystem::path fontsDirPath = resourcesDirPath / "Fonts";
	auto defaultFontPath = fontsDirPath / "Monoton-Regular.ttf";

	auto runner = NovelRT::NovelRunner(0, "NovelTD");
	auto console = NovelRT::LoggingService(NovelRT::Utilities::Misc::CONSOLE_LOG_APP);

	auto textTransform = NovelRT::Transform(NovelRT::Maths::GeoVector2<float>(0.0f, 60.0f), 0, NovelRT::Maths::GeoVector2<float>(1.0f, 1.0f));

	/*
	std::unique_ptr<NovelRT::Graphics::TextRect> textRect;

	textRect = runner.getRenderer().lock()->createTextRect(textTransform, 2, NovelRT::Graphics::RGBAConfig(0, 255, 0, 255), 70, defaultFontPath.string());
	textRect->setText("NOVELRT");
	*/

	auto canvasContext = std::make_unique<NovelTD::UI::CanvasContext>(runner, textTransform, 2);
	auto button1 = canvasContext->addButton("This is a button!");
	auto button2 = canvasContext->addButton("This one is also a button!");

	runner.getDebugService().lock()->setIsFpsCounterVisible(true);

	runner.SceneConstructionRequested += [&] {
		auto newPos = NovelRT::Maths::GeoVector2<float>(std::sin(std::clock() * 0.001) * 500, 100.0f);
		button1->setPosition(newPos);
		
		//button1->setText(std::to_string(newPos));
		canvasContext->update();
	};

	runner.runNovel();

	return 0;
}
