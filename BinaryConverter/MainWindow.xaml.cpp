#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

#include "BinaryConverter/BinaryConverter.h"

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::BinaryConverter::implementation
{
    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainWindow::Convert_Click(IInspectable const&, RoutedEventArgs const&)
    {
        const std::wstring content = ContentText().Text().c_str();

        FBinaryConverter binaryConverter;
        const std::wstring converted = binaryConverter.Encode(content);

        ConvertedText().Text(winrt::to_hstring(converted.c_str()));
    }
}
