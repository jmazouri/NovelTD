#include "../../include/NovelTD.h"

namespace NovelTD::UI {
    unsigned long CanvasContext::_currentId = 0;

    CanvasContext::CanvasContext(NovelRT::NovelRunner& runner, const NovelRT::Transform& transform, int layer): _runner(runner), _controlMap() {
        position = NovelRT::Maths::GeoVector2<float>(0.0f, 0.0f);
    }

    void CanvasContext::update() {
        for (auto key : _controlMap) {
            key.second->transform.position() = this->position + key.second->localTransform.position();
            key.second->update();
        }
    }

    std::shared_ptr<Button> CanvasContext::addButton(const std::string& text) {
        auto button = std::make_shared<Button>(_runner, 0);
        button->setText(text);

        _currentId++;

        this->_controlMap[_currentId] = button;
        return button;
    }
}

/*
RenderObject::RenderObject(const Transform& transform, int layer, ShaderProgram shaderProgram, std::weak_ptr<Camera> camera) :
    WorldObject(transform, layer),
    */