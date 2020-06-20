#ifndef NOVELTD_IMGUIHELPER
#define NOVELTD_IMGUIHELPER

namespace NovelTD::UI {
	class ImguiHelper {

		bool show_demo_window = true;

	public:
		void init(const std::shared_ptr<NovelRT::Windowing::WindowingService> windowingService);
		void update();
		void dispose();
	};
}
#endif