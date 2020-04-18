#ifndef NOVELTD_BUTTON
#define NOVELTD_BUTTON

namespace NovelTD::UI {
	class Button : public ControlBase {

		std::unique_ptr<NovelRT::Graphics::TextRect> _textRect;
		static std::filesystem::path _fontPath;

	public:

		Button(const NovelRT::NovelRunner& runner, int layer);
		void update();

		std::string getText() const;
		void setText(const std::string& value);
	};
}

#endif