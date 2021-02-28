Util::LocalPlayerPawn = localPlayerPawn;
			Util::LocalPlayerController = localPlayerController;*/
			hooks::ProcessEvent(localPlayerPawn, addresses::IsInVehicle, &InVehicle, 0);
			std::vector<PVOID> playerPawns;

			for (auto li = 0UL; li < ReadDWORD(world, offsets::World::Levels + sizeof(PVOID)); ++li) {
				auto levels = ReadPointer(world, 0x138); //keks
				if (!levels) break;

				auto level = ReadPointer(levels, li * sizeof(PVOID));
				if (!level) continue;

				for (auto ai = 0UL; ai < ReadPointer(level, offsets::Level::AActors + sizeof(PVOID)); ++ai) {
					auto actors = ReadPointer(level, offsets::Level::AActors);
					if (!actors) break;

					auto name = Util::GetObjectFirstName(pawn);
					if (wcsstr(name.c_str(), L"PlayerPawn_Athena_C") || wcsstr(name.c_str(), L"PlayerPawn_Athena_Phoebe_C") || wcsstr(name.c_str(), L"BP_MangPlayerPawn") || wcsstr(name.c_str(), L"HoagieVehicle_C") || wcsstr(name.c_str(), L"BasicCar") || wcsstr(name.c_str(), L"Taxi")) {
						playerPawns.push_back(pawn);
				}
