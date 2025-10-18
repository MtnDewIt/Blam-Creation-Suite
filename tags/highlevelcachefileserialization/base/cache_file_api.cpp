#include "highlevelcachefileserialization-private-pch.h"

BCS_RESULT get_cache_file_reader_engine_and_platform(const char* filepath, s_engine_platform_build* engine_platform_build)
{
	BCS_VALIDATE_ARGUMENT(filepath);

	size_t buffer_length = strlen(filepath);
	wchar_t* buffer = new(_alloca(sizeof(wchar_t) * (buffer_length + 1))) wchar_t[buffer_length];
	mbstowcs(buffer, filepath, buffer_length + 1);

	return get_cache_file_reader_engine_and_platform(buffer, engine_platform_build);
}

BCS_RESULT get_cache_file_reader_engine_and_platform(const wchar_t* filepath, s_engine_platform_build* engine_platform_build)
{
	BCS_VALIDATE_ARGUMENT(filepath);
	BCS_VALIDATE_ARGUMENT(engine_platform_build);

	FILE* file_handle = _wfopen(filepath, L"rb");
	if (file_handle == nullptr)
	{
		return BCS_E_FAIL;
	}
	_fseeki64(file_handle, 0, SEEK_SET);

	if (wcscmp(filesystem_extract_filepath_filename(filepath), L"tags.dat") == 0)
	{
		eldorado::s_cache_file_section_header section_header;
		if (!fread(&section_header, 1, sizeof(section_header), file_handle)) // #TODO: pipe BCS result
		{
			return BCS_E_FAIL;
		}
		_fseeki64(file_handle, 0, SEEK_SET);

		c_static_string<32> date_string;
		file_date_format_for_output_extended(&section_header.creation_date, date_string.get_buffer(), date_string.max_length());

		if (strcmp(date_string.get_buffer(), "2015-3-20 14:40:23.949") == 0)
		{
			*engine_platform_build = { _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_106708_cert_ms23 };
			return BCS_S_OK;
		}

		if (strcmp(date_string.get_buffer(), "2015-4-10 11:37:39.234") == 0) 
		{
			*engine_platform_build = { _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_155080_cert_ms23 };

			// #TODO: Handle thse builds (They share the same timestamp)
			//*engine_platform_build = { _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_171227_cert_ms23 };
			//*engine_platform_build = { _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_177150_cert_ms23 };

			return BCS_S_OK;
		}

		if (strcmp(date_string.get_buffer(), "2015-5-28 13:28:6.234") == 0)
		{
			*engine_platform_build = { _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_235640_cert_ms25 };
			return BCS_S_OK;
		}

		if (strcmp(date_string.get_buffer(), "2015-6-12 13:42:28.644") == 0)
		{
			*engine_platform_build = { _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_301003_cert_MS26_new };
			return BCS_S_OK;
		}

		if (strcmp(date_string.get_buffer(), "2015-6-29 9:41:56.45") == 0)
		{
			*engine_platform_build = { _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_332089_Live };
			return BCS_S_OK;
		}

		if (strcmp(date_string.get_buffer(), "2015-7-15 11:3:59.611") == 0)
		{
			*engine_platform_build = { _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_373869_Live };
			return BCS_S_OK;
		}

		if (strcmp(date_string.get_buffer(), "2015-8-1 14:19:18.911") == 0)
		{
			*engine_platform_build = { _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_416138_Live };
			return BCS_S_OK;
		}

		if (strcmp(date_string.get_buffer(), "2015-8-7 13:56:43.415") == 0)
		{
			*engine_platform_build = { _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_430653_Live };
			return BCS_S_OK;
		}

		if (strcmp(date_string.get_buffer(), "2015-8-19 9:47:11.625") == 0)
		{
			*engine_platform_build = { _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_454665_Live };
			return BCS_S_OK;
		}

		if (strcmp(date_string.get_buffer(), "2015-8-27 15:51:4.580") == 0)
		{
			*engine_platform_build = { _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_479394_Live };
			return BCS_S_OK;
		}

		if (strcmp(date_string.get_buffer(), "2015-9-4 13:36:11.687") == 0)
		{
			*engine_platform_build = { _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_498295_Live };
			return BCS_S_OK;
		}

		if (strcmp(date_string.get_buffer(), "2015-9-16 14:59:54.594") == 0)
		{
			*engine_platform_build = { _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_530945_Live };
			return BCS_S_OK;
		}

		if (strcmp(date_string.get_buffer(), "2015-9-17 11:53:39.863") == 0)
		{
			*engine_platform_build = { _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_533032_Live };
			return BCS_S_OK;
		}

		if (strcmp(date_string.get_buffer(), "2015-9-29 10:14:31.955") == 0)
		{
			*engine_platform_build = { _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_554482_Live };
			return BCS_S_OK;
		}

		if (strcmp(date_string.get_buffer(), "2015-10-1 16:2:13.69") == 0)
		{
			*engine_platform_build = { _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_571698_Live };
			return BCS_S_OK;
		}

		if (strcmp(date_string.get_buffer(), "2015-10-15 10:57:15.177") == 0)
		{
			*engine_platform_build = { _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_604673_Live };
			return BCS_S_OK;
		}

		if (strcmp(date_string.get_buffer(), "2015-11-26 10:26:2.893") == 0)
		{
			*engine_platform_build = { _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_700255_cert_ms30_oct19 };
			return BCS_S_OK;
		}
	}
	else 
	{
		s_cache_file_header header;
		if (!fread(&header, 1, sizeof(header), file_handle)) // #TODO: pipe BCS result
		{
			return BCS_E_FAIL;
		}
		_fseeki64(file_handle, 0, SEEK_SET);

		if (header.header_signature == _byteswap_ulong('mohd'))
		{
			// #TODO: Support Halo 5 Forge
			// #TODO: Detect version based off executable?

			switch (header.version)
			{
			case 48:
			{
				*engine_platform_build = { _engine_type_haloinfinite, _platform_type_pc_64bit, _build_infinite_FLT002INT_199229_21_07_20_0001 };
				return BCS_S_OK;
			}
			break;
			case 51:
			{
				*engine_platform_build = { _engine_type_haloinfinite, _platform_type_pc_64bit, _build_infinite_HIFLTA_202700_21_09_06_0001 };
				*engine_platform_build = { _engine_type_haloinfinite, _platform_type_pc_64bit, _build_infinite_HIREL_209048_21_12_09_1546 }; // #TODO: detect version of 51s
				return BCS_S_OK;
			}
			break;
			case 53:
			{
				*engine_platform_build = { _engine_type_haloinfinite, _platform_type_pc_64bit, _build_not_set }; // #TODO: Handle infinite release
				return BCS_S_OK;
			}
			break;
			}
		}

		bool is_big_endian = false;
		if (header.header_signature == _byteswap_ulong('head'))
		{
			is_big_endian = true;
			byteswap_inplace(header);
		}

		if (header.header_signature == 'head')
		{
			switch (header.version)
			{
			case 5:
			{
				halo1::pc32::s_cache_file_header header;
				if (!fread(&header, 1, sizeof(header), file_handle)) // #TODO: pipe BCS result
				{
					return BCS_E_FAIL;
				}

				if (header.header_signature == 'head' && header.footer_signature == 'foot')
				{
					if (strcmp(header.build_number.get_buffer(), "01.10.12.2276") == 0)
					{
						*engine_platform_build = { _engine_type_halo1, _platform_type_xbox, _build_halo1_xbox };
						return BCS_S_OK;
					}

					if (header.build_number.is_empty())
					{
						*engine_platform_build = { _engine_type_stubbs, _platform_type_pc_64bit, _build_stubbs };
						return BCS_S_OK;
					}

					// #TODO: check for 32bit stubbs
					//if (header.build_number.is_empty()) 
					//{
					//	*engine_platform_build = { _engine_type_stubbs, _platform_type_pc_32bit, _build_stubbs };
					//	return BCS_S_OK;
					//}
				}
			}
			break;
			case 6:
			{
				halo1::pc32::s_cache_file_header header;
				if (!fread(&header, 1, sizeof(header), file_handle)) // #TODO: pipe BCS result
				{
					return BCS_E_FAIL;
				}

				if (header.header_signature == 'head' && header.footer_signature == 'foot')
				{
					if (strcmp(header.build_number.get_buffer(), "01.05.22.0268") == 0)
					{
						*engine_platform_build = { _engine_type_halo1, _platform_type_pc_32bit, _build_halo1_beta_01_05_22_0268 };
						return BCS_S_OK;
					}
				}
			}
			break;
			case 7:
			{
				halo1::pc32::s_cache_file_header header;
				if (!fread(&header, 1, sizeof(header), file_handle)) // #TODO: pipe BCS result
				{
					return BCS_E_FAIL;
				}

				if (header.header_signature == 'head' && header.footer_signature == 'foot')
				{
					if (strcmp(header.build_number.get_buffer(), "01.00.00.0564") == 0)
					{
						*engine_platform_build = { _engine_type_halo1, _platform_type_pc_32bit, _build_halo1_pc_retail };
						return BCS_S_OK;
					}
				}
			}
			break;
			case 8:
			{
				halo2::xbox::alpha::s_cache_file_header halo2_alpha_header;
				if (!fread(&halo2_alpha_header, 1, sizeof(halo2_alpha_header), file_handle)) // #TODO: pipe BCS result
				{
					return BCS_E_FAIL;
				}
				_fseeki64(file_handle, 0, SEEK_SET);

				if (halo2_alpha_header.header_signature == 'head' && halo2_alpha_header.footer_signature == 'foot')
				{
					if (strcmp(halo2_alpha_header.build_number.get_buffer(), "02.01.07.4998") == 0)
					{
						// #TODO: Add missing build type for Halo 2 Alpha
						*engine_platform_build = { _engine_type_halo2, _platform_type_xbox, _build_not_set };
						return BCS_S_OK;
					}
				}

				halo2::xbox::s_cache_file_header halo2_xbox_header;
				if (!fread(&halo2_xbox_header, 1, sizeof(halo2_xbox_header), file_handle)) // #TODO: pipe BCS result
				{
					return BCS_E_FAIL;
				}
				_fseeki64(file_handle, 0, SEEK_SET);

				if (halo2_xbox_header.header_signature == 'head' && halo2_xbox_header.footer_signature == 'foot')
				{
					if (strcmp(halo2_xbox_header.build_number.get_buffer(), "02.06.28.07902") == 0)
					{
						// #TODO: Add missing build type for Halo 2 Beta
						*engine_platform_build = { _engine_type_halo2, _platform_type_xbox, _build_not_set };
						return BCS_S_OK;
					}

					if (strcmp(halo2_xbox_header.build_number.get_buffer(), "02.09.27.09809") == 0)
					{
						*engine_platform_build = { _engine_type_halo2, _platform_type_xbox, _build_not_set };
						return BCS_S_OK;
					}
				}

				halo2::pc32::s_cache_file_header halo2_vista_header;
				if (!fread(&halo2_vista_header, 1, sizeof(halo2_vista_header), file_handle)) // #TODO: pipe BCS result
				{
					return BCS_E_FAIL;
				}
				_fseeki64(file_handle, 0, SEEK_SET);

				if (halo2_vista_header.header_signature == 'head' && halo2_vista_header.footer_signature == 'foot')
				{
					if (strcmp(halo2_vista_header.build_number.get_buffer(), "11081.07.04.30.0934.main") == 0)
					{
						*engine_platform_build = { _engine_type_halo2, _platform_type_pc_32bit, _build_not_set };
						return BCS_S_OK;
					}
				}
			}
			break;
			case 9:
			{
				halo3::xbox360::beta::s_cache_file_header header;
				if (!fread(&header, 1, sizeof(header), file_handle)) // #TODO: pipe BCS result
				{
					return BCS_E_FAIL;
				}
				byteswap_inplace(header);

				if (header.header_signature == 'head' && header.footer_signature == 'foot')
				{
					if (strcmp(header.build_number.get_buffer(), "09699.07.05.01.1534.delta") == 0)
					{
						// #TODO: Add missing build type for Halo 3 Beta
						*engine_platform_build = { _engine_type_halo3, _platform_type_xbox_360, _build_not_set };
						return BCS_S_OK;
					}
				}
			}
			break;
			case 11:
			{
				if (is_big_endian)
				{
					halo3::xbox360::s_cache_file_header halo3_header;
					if (!fread(&halo3_header, 1, sizeof(halo3_header), file_handle)) // #TODO: pipe BCS result
					{
						return BCS_E_FAIL;
					}
					_fseeki64(file_handle, 0, SEEK_SET);

					byteswap_inplace(halo3_header);

					if (halo3_header.header_signature == 'head' && halo3_header.footer_signature == 'foot')
					{
						if (strcmp(halo3_header.build_number.get_buffer(), "11855.07.08.20.2317.halo3_ship") == 0 ||
							strcmp(halo3_header.build_number.get_buffer(), "12065.08.08.26.0819.halo3_ship") == 0)
						{
							*engine_platform_build = { _engine_type_halo3, _platform_type_xbox_360, _build_not_set };
							return BCS_S_OK;
						}
					}

					halo3odst::xbox360::s_cache_file_header halo3odst_header;
					if (!fread(&halo3odst_header, 1, sizeof(halo3odst_header), file_handle)) // #TODO: pipe BCS result
					{
						return BCS_E_FAIL;
					}
					_fseeki64(file_handle, 0, SEEK_SET);

					byteswap_inplace(halo3odst_header);

					if (halo3odst_header.header_signature == 'head' && halo3odst_header.footer_signature == 'foot')
					{
						if (strcmp(halo3odst_header.build_number.get_buffer(), "13895.09.04.27.2201.atlas_relea") == 0)
						{
							*engine_platform_build = { _engine_type_halo3odst, _platform_type_xbox_360, _build_not_set };
							return BCS_S_OK;
						}
					}
				}
				else
				{
					halo3::xboxone::s_cache_file_header header;
					if (!fread(&header, 1, sizeof(header), file_handle)) // #TODO: pipe BCS result
					{
						return BCS_E_FAIL;
					}

					if (header.header_signature == 'head' && header.footer_signature == 'foot')
					{
						if (strcmp(header.build_number.get_buffer(), "Oct  1 2014 16:20:07") == 0 ||
							strcmp(header.build_number.get_buffer(), "Oct 30 2014 19:01:55") == 0)
						{
							*engine_platform_build = { _engine_type_halo3, _platform_type_xbox_one, _build_not_set };
							return BCS_S_OK;
						}
					}
				}
			}
			break;
			case 12:
			{
				haloreach::xbox360::alpha::s_cache_file_header haloreach_alpha_header;
				if (!fread(&haloreach_alpha_header, 1, sizeof(haloreach_alpha_header), file_handle)) // #TODO: pipe BCS result
				{
					return BCS_E_FAIL;
				}
				_fseeki64(file_handle, 0, SEEK_SET);

				byteswap_inplace(haloreach_alpha_header);

				if (haloreach_alpha_header.header_signature == 'head' && haloreach_alpha_header.footer_signature == 'foot')
				{
					if (strcmp(haloreach_alpha_header.build_number.get_buffer(), "08516.10.02.19.1607.omaha_alpha") == 0)
					{
						// #TODO: Add missing build type Halo Reach Alpha
						*engine_platform_build = { _engine_type_haloreach, _platform_type_xbox_360, _build_not_set };
						return BCS_S_OK;
					}

					if (strcmp(haloreach_alpha_header.build_number.get_buffer(), "09449.10.03.25.1545.omaha_beta") == 0)
					{
						// #TODO: Add missing build type Halo Reach Pre Beta
						*engine_platform_build = { _engine_type_haloreach, _platform_type_xbox_360, _build_not_set };
						return BCS_S_OK;
					}

					if (strcmp(haloreach_alpha_header.build_number.get_buffer(), "09730.10.04.09.1309.omaha_delta") == 0)
					{
						// #TODO: Add missing build type Halo Reach Beta
						*engine_platform_build = { _engine_type_haloreach, _platform_type_xbox_360, _build_not_set };
						return BCS_S_OK;
					}
				}

				haloreach::xbox360::s_cache_file_header haloreach_header;
				if (!fread(&haloreach_header, 1, sizeof(haloreach_header), file_handle)) // #TODO: pipe BCS result
				{
					return BCS_E_FAIL;
				}
				_fseeki64(file_handle, 0, SEEK_SET);

				byteswap_inplace(haloreach_header);

				if (haloreach_header.header_signature == 'head' && haloreach_header.footer_signature == 'foot')
				{
					if (strcmp(haloreach_header.build_number.get_buffer(), "11860.10.07.24.0147.omaha_relea") == 0)
					{
						*engine_platform_build = { _engine_type_haloreach, _platform_type_xbox_360, _build_not_set };
						return BCS_S_OK;
					}
				}

				halo4::xbox360::s_cache_file_header halo4_header;
				if (!fread(&halo4_header, 1, sizeof(halo4_header), file_handle)) // #TODO: pipe BCS result
				{
					return BCS_E_FAIL;
				}
				_fseeki64(file_handle, 0, SEEK_SET);

				byteswap_inplace(halo4_header);

				if (halo4_header.header_signature == 'head' && halo4_header.footer_signature == 'foot')
				{
					if (strcmp(halo4_header.build_number.get_buffer(), "15119.12.05.31.0400.e3m60") == 0)
					{
						// #TODO: Add missing build type Halo 4 E3
						*engine_platform_build = { _engine_type_halo4, _platform_type_xbox_360, _build_not_set };
						return BCS_S_OK;
					}

					if (strcmp(halo4_header.build_number.get_buffer(), "20810.12.09.22.1647.main") == 0 ||
						strcmp(halo4_header.build_number.get_buffer(), "21122.12.11.21.0101.main") == 0 ||
						strcmp(halo4_header.build_number.get_buffer(), "21165.12.12.12.0112.main") == 0 ||
						strcmp(halo4_header.build_number.get_buffer(), "21339.13.02.05.0117.main") == 0 ||
						strcmp(halo4_header.build_number.get_buffer(), "21391.13.03.13.1711.main") == 0)
					{
						*engine_platform_build = { _engine_type_halo4, _platform_type_xbox_360, _build_not_set };
						return BCS_S_OK;
					}
				}
			}
			break;
			case 13:
			{
				int8_t engine_type;
				_fseeki64(file_handle, 0xC, SEEK_SET);
				if (!fread(&engine_type, 1, sizeof(engine_type), file_handle))
				{
					return BCS_E_FAIL;
				}
				_fseeki64(file_handle, 0, SEEK_SET);

				switch (engine_type)
				{
				case 0:
				{
					halo1::pc64::s_cache_file_header header;
					if (!fread(&header, 1, sizeof(header), file_handle)) // #TODO: pipe BCS result
					{
						return BCS_E_FAIL;
					}

					if (header.header_signature == 'head' && header.footer_signature == 'foot')
					{
						*engine_platform_build = { _engine_type_halo1, _platform_type_pc_64bit, _build_not_set };
						return BCS_S_OK;
					}
				}
				break;
				case 1:
				{
					halo2::pc64::s_cache_file_header header;
					if (!fread(&header, 1, sizeof(header), file_handle)) // #TODO: pipe BCS result
					{
						return BCS_E_FAIL;
					}

					if (header.header_signature == 'head' && header.footer_signature == 'foot')
					{
						*engine_platform_build = { _engine_type_halo2, _platform_type_pc_64bit, _build_not_set };
						return BCS_S_OK;
					}
				}
				break;
				case 2:
				{
					halo3::pc::s_cache_file_header header;
					if (!fread(&header, 1, sizeof(header), file_handle)) // #TODO: pipe BCS result
					{
						return BCS_E_FAIL;
					}

					if (header.header_signature == 'head' && header.footer_signature == 'foot')
					{
						*engine_platform_build = { _engine_type_halo3, _platform_type_pc_64bit, _build_not_set };
						return BCS_S_OK;
					}
				}
				break;
				case 3:
				{
					halo4::pc::s_cache_file_header header;
					if (!fread(&header, 1, sizeof(header), file_handle)) // #TODO: pipe BCS result
					{
						return BCS_E_FAIL;
					}

					if (header.header_signature == 'head' && header.footer_signature == 'foot')
					{
						*engine_platform_build = { _engine_type_halo4, _platform_type_pc_64bit, _build_not_set };
						return BCS_S_OK;
					}
				}
				break;
				case 4:
				{
					halo4::pc::s_cache_file_header header;
					if (!fread(&header, 1, sizeof(header), file_handle)) // #TODO: pipe BCS result
					{
						return BCS_E_FAIL;
					}

					if (header.header_signature == 'head' && header.footer_signature == 'foot')
					{
						*engine_platform_build = { _engine_type_groundhog, _platform_type_pc_64bit, _build_not_set };
						return BCS_S_OK;
					}
				}
				break;
				case 5:
				{
					halo3odst::pc::s_cache_file_header header;
					if (!fread(&header, 1, sizeof(header), file_handle)) // #TODO: pipe BCS result
					{
						return BCS_E_FAIL;
					}

					if (header.header_signature == 'head' && header.footer_signature == 'foot')
					{
						*engine_platform_build = { _engine_type_halo3odst, _platform_type_pc_64bit, _build_not_set };
						return BCS_S_OK;
					}
				}
				break;
				case 6:
				{
					haloreach::pc::s_cache_file_header header;
					if (!fread(&header, 1, sizeof(header), file_handle)) // #TODO: pipe BCS result
					{
						return BCS_E_FAIL;
					}

					if (header.header_signature == 'head' && header.footer_signature == 'foot')
					{
						*engine_platform_build = { _engine_type_haloreach, _platform_type_pc_64bit, _build_not_set };
						return BCS_S_OK;
					}
				}
				break;
				}
			}
			break;
			case 609:
			{
				halo1::pc32::s_cache_file_header header;
				if (!fread(&header, 1, sizeof(header), file_handle)) // #TODO: pipe BCS result
				{
					return BCS_E_FAIL;
				}

				if (header.header_signature == 'head' && header.footer_signature == 'foot')
				{
					if (strcmp(header.build_number.get_buffer(), "01.00.00.0609") == 0)
					{
						*engine_platform_build = { _engine_type_halo1, _platform_type_pc_32bit, _build_halo1_custom_edition };
						return BCS_S_OK;
					}
				}
			}
			break;
			}
		}
		else
		{
			halo1::demo::s_cache_file_header header;
			if (!fread(&header, 1, sizeof(header), file_handle)) // #TODO: pipe BCS result
			{
				return BCS_E_FAIL;
			}

			if (header.version == 6)
			{
				if (header.header_signature == 'Ehed' && header.footer_signature == 'Gfot')
				{
					if (strcmp(header.build_number.get_buffer(), "01.00.00.0576") == 0)
					{
						*engine_platform_build = { _engine_type_halo1, _platform_type_pc_32bit, _build_halo1_demo };
						return BCS_S_OK;
					}
				}
			}
		}
	}

	fclose(file_handle);

	return BCS_E_FAIL;
}

BCS_RESULT open_cache_file_reader(const char* filepath, s_engine_platform_build engine_platform_build, bool read_only, bool memory_mapped_file, c_cache_file_reader** cache_file)
{
	BCS_VALIDATE_ARGUMENT(filepath);

	size_t buffer_length = strlen(filepath);
	wchar_t* buffer = new(_alloca(sizeof(wchar_t) * (buffer_length + 1))) wchar_t[buffer_length];
	mbstowcs(buffer, filepath, buffer_length + 1);

	return open_cache_file_reader(buffer, engine_platform_build, read_only, memory_mapped_file, cache_file);
}

BCS_RESULT open_cache_file_reader(const wchar_t* filepath, s_engine_platform_build engine_platform_build, bool read_only, bool memory_mapped_file, c_cache_file_reader** cache_file)
{
	BCS_VALIDATE_ARGUMENT(filepath);
	BCS_VALIDATE_ARGUMENT(engine_platform_build);
	BCS_VALIDATE_ARGUMENT(IS_VALID_BOOLEAN(read_only));
	BCS_VALIDATE_ARGUMENT(IS_VALID_BOOLEAN(memory_mapped_file));
	BCS_VALIDATE_ARGUMENT(cache_file);

	// #TODO plugin support

	try
	{
		switch (engine_platform_build.engine_type)
		{
#if defined(BCS_BUILD_HIGH_LEVEL_HALO1) || defined(BCS_BUILD_HIGH_LEVEL_STUBBS)
		case _engine_type_stubbs:
		case _engine_type_halo1:
		{
			*cache_file = new() c_halo1_cache_file_reader(filepath, engine_platform_build);
			return BCS_S_OK;
		}
		break;
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_HALO2)
		case _engine_type_halo2:
		{
			*cache_file = new() c_halo2_cache_file_reader(filepath, engine_platform_build);
			return BCS_S_OK;
		}
		break;
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_HALO3)
		case _engine_type_halo3:
		{
			*cache_file = new() c_halo3_cache_file_reader(filepath, engine_platform_build);
			return BCS_S_OK;
		}
		break;
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_HALO3ODST)
		case _engine_type_halo3odst:
		{
			*cache_file = new() c_halo3odst_cache_file_reader(filepath, engine_platform_build);
			return BCS_S_OK;
		}
		break;
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_ELDORADO)
		case _engine_type_eldorado:
		{
			*cache_file = new() c_eldorado_cache_file_reader(wremove(filepath, L"\\maps\\tags.dat"), engine_platform_build);
			return BCS_S_OK;
		}
		break;
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_HALOREACH)
		case _engine_type_haloreach:
		{
			*cache_file = new() c_haloreach_cache_file_reader(filepath, engine_platform_build);
			return BCS_S_OK;
		}
		break;
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_HALO4)
		case _engine_type_halo4:
		{
			*cache_file = new() c_halo4_cache_file_reader(filepath, engine_platform_build);
			return BCS_S_OK;
		}
		break;
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_GROUNDHOG)
		case _engine_type_groundhog:
		{
			*cache_file = new() c_groundhog_cache_file_reader(filepath, engine_platform_build);
			return BCS_S_OK;
		}
		break;
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_HALOINFINITE)
		case _engine_type_haloinfinite:
		{
			*cache_file = new() c_infinite_module_file_reader(filepath, engine_platform_build);
			return BCS_S_OK;
		}
#endif
		default:
			return BCS_E_UNSUPPORTED;
		}
	}
	catch (BCS_RESULT error_result)
	{
		return error_result;
	}
	catch (...)
	{
		return BCS_E_UNEXPECTED;
	}

	return BCS_E_UNSUPPORTED;
}

BCS_RESULT close_cache_file_reader(c_cache_file_reader* cache_reader)
{
	delete cache_reader;

	return BCS_S_OK;
}

BCS_RESULT get_cache_file_reader_build_info(c_cache_file_reader* cache_reader, s_cache_file_build_info* build_info)
{
	BCS_VALIDATE_ARGUMENT(build_info);
	return cache_reader->get_build_info(*build_info);
}

BCS_RESULT get_cache_file_reader_debug_info(c_cache_file_reader* cache_reader, s_cache_file_debug_info* debug_info)
{
	BCS_VALIDATE_ARGUMENT(debug_info);
	return cache_reader->get_debug_info(*debug_info);
}

BCS_RESULT get_cache_file_reader_buffer(c_cache_file_reader* cache_reader, e_cache_file_buffer_index buffer_index, s_cache_file_buffer_info* buffer_info)
{
	BCS_VALIDATE_ARGUMENT(cache_reader);
	BCS_VALIDATE_ARGUMENT(buffer_index < k_num_cache_file_buffers);
	BCS_VALIDATE_ARGUMENT(buffer_info);

	return cache_reader->get_buffer(buffer_index, *buffer_info);
}

BCS_RESULT get_cache_file_reader_buffers(c_cache_file_reader* cache_reader, s_cache_file_buffers_info* buffers_info)
{
	BCS_VALIDATE_ARGUMENT(buffers_info);
	return cache_reader->get_buffers(*buffers_info);
}

BCS_RESULT create_cache_cluster(c_cache_file_reader** cache_readers, uint32_t cache_reader_count, s_engine_platform_build engine_platform_build, c_cache_cluster** cache_cluster)
{
	BCS_VALIDATE_ARGUMENT(cache_readers);
	BCS_VALIDATE_ARGUMENT(cache_reader_count > 0);
	BCS_VALIDATE_ARGUMENT(cache_cluster);

	try
	{
#if defined(BCS_BUILD_HIGH_LEVEL_HALO1)
		if (c_halo1_cache_file_reader* halo1_cache_file = dynamic_cast<c_halo1_cache_file_reader*>(*cache_readers))
		{
			*cache_cluster = new() c_halo1_cache_cluster(reinterpret_cast<c_halo1_cache_file_reader**>(cache_readers), cache_reader_count, engine_platform_build);

			return BCS_S_OK;
		}
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_HALO2)
		if (c_halo2_cache_file_reader* halo2_cache_file = dynamic_cast<c_halo2_cache_file_reader*>(*cache_readers))
		{
			*cache_cluster = new() c_halo2_cache_cluster(reinterpret_cast<c_halo2_cache_file_reader**>(cache_readers), cache_reader_count, engine_platform_build);
		
			return BCS_S_OK;
		}
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_HALO3)
		if (c_halo3_cache_file_reader* halo3_cache_file = dynamic_cast<c_halo3_cache_file_reader*>(*cache_readers))
		{
			*cache_cluster = new() c_halo3_cache_cluster(reinterpret_cast<c_halo3_cache_file_reader**>(cache_readers), cache_reader_count, engine_platform_build);

			return BCS_S_OK;
		}
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_HALO3ODST)
		if (c_halo3odst_cache_file_reader* halo3odst_cache_file = dynamic_cast<c_halo3odst_cache_file_reader*>(*cache_readers))
		{
			*cache_cluster = new() c_halo3odst_cache_cluster(reinterpret_cast<c_halo3odst_cache_file_reader**>(cache_readers), cache_reader_count, engine_platform_build);

			return BCS_S_OK;
		}
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_ELDORADO)
		if (c_eldorado_cache_file_reader* eldorado_cache_file = dynamic_cast<c_eldorado_cache_file_reader*>(*cache_readers))
		{
			*cache_cluster = new() c_eldorado_cache_cluster(reinterpret_cast<c_eldorado_cache_file_reader**>(cache_readers), cache_reader_count, engine_platform_build);

			return BCS_S_OK;
		}
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_HALOREACH)
		if (c_haloreach_cache_file_reader* haloreach_cache_file = dynamic_cast<c_haloreach_cache_file_reader*>(*cache_readers))
		{
			*cache_cluster = new() c_haloreach_cache_cluster(reinterpret_cast<c_haloreach_cache_file_reader**>(cache_readers), cache_reader_count, engine_platform_build);
		
			return BCS_S_OK;
		}
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_HALO4)
		if (c_halo4_cache_file_reader* halo4_cache_file = dynamic_cast<c_halo4_cache_file_reader*>(*cache_readers))
		{
			*cache_cluster = new() c_halo4_cache_cluster(reinterpret_cast<c_halo4_cache_file_reader**>(cache_readers), cache_reader_count, engine_platform_build);

			return BCS_S_OK;
		}
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_GROUNDHOG)
		if (c_groundhog_cache_file_reader* groundhog_cache_file = dynamic_cast<c_groundhog_cache_file_reader*>(*cache_readers))
		{
			*cache_cluster = new() c_groundhog_cache_cluster(reinterpret_cast<c_groundhog_cache_file_reader**>(cache_readers), cache_reader_count, engine_platform_build);
		
			return BCS_S_OK;
		}
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_HALOINFINITE)
		if (c_infinite_module_file_reader* infinite_module_file = dynamic_cast<c_infinite_module_file_reader*>(*cache_readers))
		{
			*cache_cluster = new() c_infinite_cache_cluster(reinterpret_cast<c_infinite_module_file_reader**>(cache_readers), cache_reader_count, engine_platform_build);

			return BCS_S_OK;
		}
#endif
	}
	catch (BCS_RESULT error_result)
	{
		return error_result;
	}
	catch (...)
	{
		return BCS_E_UNEXPECTED;
	}

	return BCS_E_FAIL;
}

BCS_RESULT destroy_cache_cluster(c_cache_cluster* cache_cluster)
{
	BCS_VALIDATE_ARGUMENT(cache_cluster);

	delete cache_cluster;

	return BCS_S_OK;
}

BCS_RESULT get_cache_file_debug_reader(c_cache_cluster* cache_cluster, c_cache_file_reader* cache_reader, c_debug_reader** debug_reader)
{
	BCS_VALIDATE_ARGUMENT(cache_cluster);
	BCS_VALIDATE_ARGUMENT(cache_reader);
	BCS_VALIDATE_ARGUMENT(debug_reader);

	BCS_RESULT result = BCS_E_NOT_IMPLEMENTED;
#if defined(BCS_BUILD_HIGH_LEVEL_HALO1)
	if (c_halo1_cache_cluster* halo1_cache_cluster = dynamic_cast<c_halo1_cache_cluster*>(cache_cluster))
	{
		result = halo1_cache_cluster->get_debug_reader(
			*static_cast<c_halo1_cache_file_reader*>(cache_reader),
			*reinterpret_cast<c_halo1_debug_reader**>(debug_reader));
	}
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_HALO2)
	if (c_halo2_cache_cluster* halo2_cache_cluster = dynamic_cast<c_halo2_cache_cluster*>(cache_cluster))
	{
		result = halo2_cache_cluster->get_debug_reader(
			*static_cast<c_halo2_cache_file_reader*>(cache_reader),
			*reinterpret_cast<c_halo2_debug_reader**>(debug_reader));
	}
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_HALO3)
	if (c_halo3_cache_cluster* halo3_cache_cluster = dynamic_cast<c_halo3_cache_cluster*>(cache_cluster))
	{
		result = halo3_cache_cluster->get_debug_reader(
			*static_cast<c_halo3_cache_file_reader*>(cache_reader),
			*reinterpret_cast<c_halo3_debug_reader**>(debug_reader));
	}
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_HALO3ODST)
	if (c_halo3odst_cache_cluster* halo3odst_cache_cluster = dynamic_cast<c_halo3odst_cache_cluster*>(cache_cluster))
	{
		result = halo3odst_cache_cluster->get_debug_reader(
			*static_cast<c_halo3odst_cache_file_reader*>(cache_reader),
			*reinterpret_cast<c_halo3odst_debug_reader**>(debug_reader));
	}
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_ELDORADO)
	if (c_eldorado_cache_cluster* eldorado_cache_cluster = dynamic_cast<c_eldorado_cache_cluster*>(cache_cluster))
	{
		result = eldorado_cache_cluster->get_debug_reader(
			*static_cast<c_eldorado_cache_file_reader*>(cache_reader),
			*reinterpret_cast<c_eldorado_debug_reader**>(debug_reader));
	}
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_HALOREACH)
	if (c_haloreach_cache_cluster* haloreach_cache_cluster = dynamic_cast<c_haloreach_cache_cluster*>(cache_cluster))
	{
		result = haloreach_cache_cluster->get_debug_reader(
			*static_cast<c_haloreach_cache_file_reader*>(cache_reader),
			*reinterpret_cast<c_haloreach_debug_reader**>(debug_reader));
	}
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_HALO4)
	if (c_halo4_cache_cluster* halo4_cache_cluster = dynamic_cast<c_halo4_cache_cluster*>(cache_cluster))
	{
		result = halo4_cache_cluster->get_debug_reader(
			*static_cast<c_halo4_cache_file_reader*>(cache_reader),
			*reinterpret_cast<c_halo4_debug_reader**>(debug_reader));
	}
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_GROUNDHOG)
	if (c_groundhog_cache_cluster* groundhog_cache_cluster = dynamic_cast<c_groundhog_cache_cluster*>(cache_cluster))
	{
		result = groundhog_cache_cluster->get_debug_reader(
			*static_cast<c_groundhog_cache_file_reader*>(cache_reader),
			*reinterpret_cast<c_groundhog_debug_reader**>(debug_reader));
	}
#endif
	return result;
}

BCS_RESULT destroy_cache_file_debug_reader(c_debug_reader* debug_reader)
{
	BCS_VALIDATE_ARGUMENT(debug_reader);

	delete debug_reader;

	return BCS_S_OK;
}

BCS_RESULT get_cache_file_tag_reader(c_cache_cluster* cache_cluster, c_cache_file_reader* cache_reader, c_tag_reader** tag_reader)
{
	BCS_VALIDATE_ARGUMENT(cache_cluster);
	BCS_VALIDATE_ARGUMENT(cache_reader);
	BCS_VALIDATE_ARGUMENT(tag_reader);

	return cache_cluster->get_tag_reader(*cache_reader, *tag_reader);
}

BCS_RESULT destroy_cache_file_tag_reader(c_tag_reader* tag_reader)
{
	BCS_VALIDATE_ARGUMENT(tag_reader);

	delete tag_reader;

	return BCS_S_OK;
}

BCS_RESULT create_cache_file_resource_reader(c_cache_cluster* cache_cluster, c_cache_file_reader* cache_reader, c_resource_reader** resource_reader)
{
	BCS_VALIDATE_ARGUMENT(cache_cluster);
	BCS_VALIDATE_ARGUMENT(cache_reader);
	BCS_VALIDATE_ARGUMENT(resource_reader);

	return cache_cluster->get_resource_reader(*cache_reader, *resource_reader);
}

BCS_RESULT destroy_cache_file_resource_reader(c_resource_reader* resource_reader)
{
	BCS_VALIDATE_ARGUMENT(resource_reader);

	delete resource_reader;

	return BCS_S_OK;
}

BCS_RESULT create_cache_file_localization_reader(c_cache_cluster* cache_cluster, c_cache_file_reader* cache_reader, c_localization_reader** localization_reader)
{
	BCS_VALIDATE_ARGUMENT(cache_cluster);
	BCS_VALIDATE_ARGUMENT(cache_reader);
	BCS_VALIDATE_ARGUMENT(localization_reader);

	return cache_cluster->get_localization_reader(*cache_reader, *localization_reader);
}

BCS_RESULT destroy_cache_file_localization_reader(c_localization_reader* localization_reader)
{
	BCS_VALIDATE_ARGUMENT(localization_reader);

	delete localization_reader;

	return BCS_S_OK;
}
