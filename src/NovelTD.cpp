// NovelTD.cpp : Defines the entry point for the application.
//

#include "../include/NovelTD.h"
#include <chrono>
#include "tweeny.h"
#include "../lib/imgui/imgui.h"



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

	imgui->Update += [&] {
		static float f = 0.0f;

		ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

		ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
		//ImGui::Checkbox("Another Window", &show_another_window);

		static float pos[2] = { button1->getPosition().getX(), button1->getPosition().getX() };

		ImGui::SliderFloat2("Button Pos", pos, 0.0f, 1000.0f);
		//ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		ImGui::End();

		button1->setPosition(NovelRT::Maths::GeoVector2<float>(pos[0], pos[1]));
	};

	runner.SceneConstructionRequested += [&] {

		canvasContext->executeObjectBehaviour();
		
		if (!created) {
			imgui->init(runner.getWindowingService().lock());
			created = true;
		}

		if (created) {
			imgui->update();
		}
	};

	runner.Update += [&](NovelRT::Timing::Timestamp delta) {
		
		//auto dur = t.duration();
		//auto newStep = static_cast<float>(delta.getTicks()) / static_cast<float>(period);
		//t.step(static_cast<uint16_t>(delta.getSecondsDouble() * 1000), false);
		

		//button1->setText(std::to_string(newPos));

		canvasContext->update();
	};

	runner.runNovel();

	imgui->dispose();

	return 0;
}
