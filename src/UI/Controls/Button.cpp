#include "../../../include/NovelTD.h"

namespace NovelTD::UI {

	std::filesystem::path Button::_fontPath = NovelRT::Utilities::Misc::getExecutableDirPath() / "res" / "Fonts" / "Monoton-Regular.ttf";//"SpaceMono-Regular.ttf";

	Button::Button(const NovelRT::NovelRunner& runner, int layer) : ControlBase(layer) {
		this->_textRect =
			runner.getRenderer().lock()->createTextRect(this->transform, this->layer, NovelRT::Graphics::RGBAConfig(0, 255, 0, 255), 70, _fontPath.string());

		this->_fillRect =
			runner.getRenderer().lock()->createBasicFillRect(this->transform, this->layer + 1, NovelRT::Graphics::RGBAConfig(255, 0, 0, 150));

		this->_interactionRect =
			runner.getInteractionService().lock()->createBasicInteractionRect(this->transform, this->layer);

		this->_interactionRect->subscribedKey() = NovelRT::Input::KeyCode::LeftMouseButton;

		this->_interactionRect->Interacted += [&] {
			this->setPosition(this->getPosition() + NovelRT::Maths::GeoVector2(0.0f, 10.0f));
		};

		this->padding = 0;
	}

	std::string Button::getText() const {
		return this->_textRect->getText();
	};

	void Button::setText(const std::string& value) {
		this->_textRect->setText(value);
	};

	void Button::update() {

		auto fontSize = this->_textRect->getFontSet()->getFontSize();

		_textRect->transform().position() = this->transform.position() + NovelRT::Maths::GeoVector2<float>(0, fontSize);// + (this->padding * 0.5f));

		auto rectOffset = NovelRT::Maths::GeoVector2<float>(0.0f, fontSize * 0.66f);

		_interactionRect->transform().position() = this->transform.position() + rectOffset;
		_fillRect->transform().position() = this->transform.position() + rectOffset;

		

		//_logger.logInfo("Text is now at " + std::to_string(_textRect->transform().position().getX()) + ", " + std::to_string(_textRect->transform().position().getY()));
		//_logger.logInfo("Interaction is now at " + std::to_string(_interactionRect->transform().position().getX()) + ", " + std::to_string(_interactionRect->transform().position().getY()));
		//_logger.logInfo("Fill is now at " + std::to_string(_fillRect->transform().position().getX()) + ", " + std::to_string(_fillRect->transform().position().getY()));
		
		auto textSize = this->_textRect->getRenderedSize();

		//_logger.logInfo("Text Size " + std::to_string(textSize.getX()) + ", " + std::to_string(textSize.getY()));

		//auto boxScale = NovelRT::Maths::GeoVector2<float>(textSize.getX() + (this->padding * 4.0f), textSize.getY() + (this->padding * 2.0f));
		auto boxScale = NovelRT::Maths::GeoVector2<float>(textSize.getX(), textSize.getY());

		_interactionRect->transform().scale() = boxScale;
		_fillRect->transform().scale() = boxScale;

	}

	void Button::executeObjectBehaviour() {
		_fillRect->executeObjectBehaviour();
		_textRect->executeObjectBehaviour();
		_interactionRect->executeObjectBehaviour();
	}
}