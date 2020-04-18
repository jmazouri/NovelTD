#include "../../../include/NovelTD.h"

namespace NovelTD::UI {

	std::filesystem::path Button::_fontPath = NovelRT::Utilities::Misc::getExecutableDirPath() / "res" / "Fonts" / "Monoton-Regular.ttf";

	Button::Button(const NovelRT::NovelRunner& runner, int layer) : ControlBase(layer) {
		this->_textRect =
			runner.getRenderer().lock()->createTextRect(this->transform, this->layer, NovelRT::Graphics::RGBAConfig(0, 255, 0, 255), 70, _fontPath.string());
	}

	std::string Button::getText() const {
		return this->_textRect->getText();
	};

	void Button::setText(const std::string& value) {
		this->_textRect->setText(value);
	};

	void Button::update() {
		_textRect->executeObjectBehaviour();
	}
}