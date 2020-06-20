// NovelTD.cpp : Defines the entry point for the application.
//

#include "../include/NovelTD.h"
#include <chrono>
#include "tweeny.h"



int main()
{
	auto console = NovelRT::LoggingService(NovelRT::Utilities::Misc::CONSOLE_LOG_APP, NovelRT::LogLevel::Debug);

	auto imgui = new NovelTD::UI::ImguiHelper();

	using clock = std::chrono::high_resolution_clock;

	auto time_start = clock::now();

	auto runner = NovelRT::NovelRunner(0, "NovelTD");

	auto textTransform = NovelRT::Transform(NovelRT::Maths::GeoVector2<float>(0.0f, 0.0f), 2, NovelRT::Maths::GeoVector2<float>(1.0f, 1.0f));

	/*
	std::unique_ptr<NovelRT::Graphics::TextRect> textRect;

	textRect = runner.getRenderer().lock()->createTextRect(textTransform, 2, NovelRT::Graphics::RGBAConfig(0, 255, 0, 255), 70, defaultFontPath.string());
	textRect->setText("NOVELRT");
	*/

	auto canvasContext = std::make_unique<NovelTD::UI::CanvasContext>(runner, textTransform, 2);
	auto button1 = canvasContext->addButton("This is a button!");
	button1->setPosition(NovelRT::Maths::GeoVector2<float>(0.0f, 0.0f));

	//auto button2 = canvasContext->addButton("This one is also a button!");

	runner.getDebugService().lock()->setIsFpsCounterVisible(true);

	/*
	auto moveButton = [&](tweeny::tween<int> & t, int val) -> bool {
		button1->padding = val;

		if (t.progress() <= 0.001f) { t.forward(); }
		if (t.progress() >= 1.0f) { t.backward(); }
		return false;
	};
	*/

	//auto t = tweeny::from(0).to(50).during(2000).onStep(moveButton);//.via(tweeny::easing::circularInOut);

	bool created = false;

	runner.SceneConstructionRequested += [&] {

		if (!created) {
			imgui->init(runner.getWindowingService().lock());
			created = true;
		}

		canvasContext->executeObjectBehaviour();
	};

	runner.Update += [&](NovelRT::Timing::Timestamp delta) {
		
		
		//auto dur = t.duration();
		//auto newStep = static_cast<float>(delta.getTicks()) / static_cast<float>(period);
		//t.step(static_cast<uint16_t>(delta.getSecondsDouble() * 1000), false);
		

		//button1->setText(std::to_string(newPos));

		canvasContext->update();
		//imgui->update();
	};

	runner.runNovel();

	//imgui->dispose();

	return 0;
}
