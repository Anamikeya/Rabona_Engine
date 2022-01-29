#pragma once

#include "Rabona/Layer.h"

namespace  Rabona
{

	class RABONA_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);
	private:
		float m_Time = 0;

	};
}

