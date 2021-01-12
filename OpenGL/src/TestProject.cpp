#include "core/Application.h"
#include "TestScene.h"

class TestProject : public Application
{
public:
	TestProject()
		:Application("Test project")
	{
		setScene(new TestScene());
	}
};

int main()
{
	std::unique_ptr<TestProject> app = std::make_unique<TestProject>();
	app->Run();
}