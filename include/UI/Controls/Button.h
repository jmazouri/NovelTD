#ifndef NOVELTD_BUTTON
#define NOVELTD_BUTTON

namespace NovelTD::UI {
	class Button : public ControlBase {

		std::unique_ptr<NovelRT::Graphics::TextRect> _textRect;
		std::unique_ptr<NovelRT::Input::BasicInteractionRect> _interactionRect;
		std::unique_ptr<NovelRT::Graphics::BasicFillRect> _fillRect;

		static std::filesystem::path _fontPath;

	public:
		Button(const NovelRT::NovelRunner& runner, int layer);
		void update();
		void executeObjectBehaviour();

		std::string getText() const;
		void setText(const std::string& value);

		float padding;
	};
}

#endif